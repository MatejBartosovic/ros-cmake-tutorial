#include <iostream>
#include <ros_exectable/library.h>

int main(int argc, char** argv)
{
    std::cout << library::project_name() << std::endl;
}
