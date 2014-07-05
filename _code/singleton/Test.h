#ifndef TEST_H
#define TEST_H

#include "Singleton.h"

class Test
{
public:
    explicit Test();
    ~Test();

public:
    void run();
};

DEFINE_SINGLETON(Test)

#endif // TEST_H
