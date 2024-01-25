#include <iostream>
#include <ros_library/library.h>

int main(int argc, char** argv)
{
    std::cout << library::project_name() << std::endl;
}
