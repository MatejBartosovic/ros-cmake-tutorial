#include <gtest/gtest.h>
#include <cmake_executable/library.h>

TEST(library, project_name){
    ASSERT_EQ(library::project_name(), PROJECT_NAME);
}