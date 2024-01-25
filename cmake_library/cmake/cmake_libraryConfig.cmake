include(CMakeFindDependencyMacro)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
include(${CMAKE_CURRENT_LIST_DIR}/cmake_libraryTargets.cmake)