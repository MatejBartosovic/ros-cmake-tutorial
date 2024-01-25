cmake_minimum_required(VERSION 3.0.2)
project(ros_exectable)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
add_library(${PROJECT_NAME}_library src/library.cpp)

target_include_directories(${PROJECT_NAME}_library PRIVATE ${OpenCV_INCLUDE_DIRS} )
target_include_directories(${PROJECT_NAME}_library PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${EIGEN3_INCLUDE_DIRS} )

target_compile_definitions(${PROJECT_NAME}_library  PRIVATE -DPROJECT_NAME="${PROJECT_NAME}")

target_link_libraries(${PROJECT_NAME}_library PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)

add_executable(${PROJECT_NAME}_main src/main.cpp)

target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME}_library)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_subdirectory(test)

install(TARGETS ${PROJECT_NAME}_library
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
        )

install(TARGETS ${PROJECT_NAME}_main
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )