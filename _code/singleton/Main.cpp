#include <iostream>

#include "Test.h"

int main(int argc, char *argv[])
{
	std::cout << "Without Singleton Pattern" << std::endl;
    Test().run();
    Test().run();

    std::cout << std::endl;

	std::cout << "Using Singleton Pattern" << std::endl;
    Singleton<Test>::instance()->run();
    Test_st::instance()->run();
}
