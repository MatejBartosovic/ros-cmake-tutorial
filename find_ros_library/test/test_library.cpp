#include <gtest/gtest.h>
#include <ros_library/library.h>

TEST(library, project_name){
    ASSERT_EQ(library::project_name(), "ros_library");
}