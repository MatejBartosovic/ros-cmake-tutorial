include(FetchContent)
find_package(Threads REQUIRED)
find_package(GTest)
if (NOT (GTEST_FOUND OR GTEST_FROM_SOURCE_FOUND))
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)
endif ()

catkin_add_gtest(${PROJECT_NAME}_unittests
        test_library.cpp
        main.cpp)

target_compile_definitions(${PROJECT_NAME}_unittests  PRIVATE -DPROJECT_NAME="${PROJECT_NAME}")

target_link_libraries(${PROJECT_NAME}_unittests
        ${PROJECT_NAME}_library
        gtest
        gtest_main
        Threads::Threads
        )
