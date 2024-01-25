cmake_minimum_required(VERSION 3.0.2)
project(cmake_library VERSION 1.0.0)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_library(${PROJECT_NAME}_library src/library.cpp)

target_include_directories(${PROJECT_NAME}_library PRIVATE ${OpenCV_INCLUDE_DIRS} )
target_include_directories(${PROJECT_NAME}_library PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
target_compile_definitions(${PROJECT_NAME}_library  PRIVATE -DPROJECT_NAME="${PROJECT_NAME}")

target_link_libraries(${PROJECT_NAME}_library PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)

add_executable(${PROJECT_NAME}_main src/main.cpp)

target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME}_library)

enable_testing()
add_subdirectory(test)

install(TARGETS ${PROJECT_NAME}_library EXPORT ${PROJECT_NAME}_library DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT ${PROJECT_NAME}_library
        DESTINATION
        lib/cmake/${PROJECT_NAME}/
        NAMESPACE
        ${NAMESPACE}::
        FILE
        ${PROJECT_NAME}Targets.cmake
        )

install(
        FILES cmake/${PROJECT_NAME}Config.cmake
        DESTINATION  lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMinorVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION "lib/cmake/${PROJECT_NAME}/")

