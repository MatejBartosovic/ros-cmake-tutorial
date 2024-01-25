cmake_minimum_required(VERSION 3.0.2)
project(use_custom_ros_msg)

find_package(catkin REQUIRED COMPONENTS
  custom_ros_msg
)

catkin_package(
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${custom_ros_msg_INCLUDE_DIRS})

#add_dependencies(${PROJECT_NAME} ${custom_ros_msg_EXPORTED_TARGETS})
#add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
