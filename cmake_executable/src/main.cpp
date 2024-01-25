#include <iostream>
#include <cmake_executable/library.h>

int main(int argc, char** argv)
{
    std::cout << library::project_name() << std::endl;
}
