#include <gtest/gtest.h>
#include <ros_exectable/library.h>

TEST(library, project_name){
    ASSERT_EQ(library::project_name(), PROJECT_NAME);
}