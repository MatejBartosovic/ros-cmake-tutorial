cmake_minimum_required(VERSION 3.0.2)
project(cmake_executable)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_library(${PROJECT_NAME}_library src/library.cpp)

target_include_directories(${PROJECT_NAME}_library PRIVATE ${OpenCV_INCLUDE_DIRS} )
target_include_directories(${PROJECT_NAME}_library PUBLIC include )
target_compile_definitions(${PROJECT_NAME}_library  PRIVATE -DPROJECT_NAME="${PROJECT_NAME}")

target_link_libraries(${PROJECT_NAME}_library PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)

add_executable(${PROJECT_NAME}_main src/main.cpp)

target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME}_library)

enable_testing()
add_subdirectory(test)

install (TARGETS ${PROJECT_NAME}_main RUNTIME DESTINATION bin)
