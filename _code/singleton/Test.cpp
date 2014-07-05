#include "Test.h"

#include <iostream>

Test::Test()
{
    std::cout << "Test()" << std::endl;
}

Test::~Test()
{
    std::cout << "~Test()" << std::endl;
}

void Test::run()
{
    std::cout << "run()" << std::endl;
}
