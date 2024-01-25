cmake_minimum_required(VERSION 3.0.2)
project(find_cmake_library)

find_package(cmake_library REQUIRED)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ::cmake_library_library)

enable_testing()
add_subdirectory(test)