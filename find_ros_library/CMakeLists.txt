cmake_minimum_required(VERSION 3.0.2)
project(find_ros_library)

find_package(catkin REQUIRED COMPONENTS
  ros_library
)
catkin_package()

add_executable(${PROJECT_NAME}_main src/main.cpp)

target_link_libraries(${PROJECT_NAME}_main PRIVATE ${ros_library_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_subdirectory(test)

install(TARGETS ${PROJECT_NAME}_main
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )