cmake_minimum_required(VERSION 3.0.2)
project(ros_library)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        )

### Note that find_package are called before catkin_package()
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

#### https://answers.ros.org/question/58498/what-is-the-purpose-of-catkin_depends/
set(OpenCV_LIBRARIES ${OpenCV_LIBS})
set(Eigen3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})

### http://wiki.ros.org/catkin/CMakeLists.txt#catkin_package.28.29
catkin_package(
        INCLUDE_DIRS include
        LIBRARIES ${PROJECT_NAME}_library
        DEPENDS OpenCV Eigen3
)

### NOTE that targets are defined after catkin_package()
add_library(${PROJECT_NAME}_library src/library.cpp)

target_include_directories(${PROJECT_NAME}_library PRIVATE ${OpenCV_INCLUDE_DIRS} )
target_include_directories(${PROJECT_NAME}_library PUBLIC include )
target_compile_definitions(${PROJECT_NAME}_library  PRIVATE -DPROJECT_NAME="${PROJECT_NAME}")

target_link_libraries(${PROJECT_NAME}_library PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)

add_subdirectory(test)

install(TARGETS ${PROJECT_NAME}_library
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
        )

install(DIRECTORY include/library/
        DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}/library
        PATTERN ".svn" EXCLUDE
        )
