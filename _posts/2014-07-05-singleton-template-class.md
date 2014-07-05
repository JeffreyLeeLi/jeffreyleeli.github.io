---
layout: post
title: "Singleton Template Class"
description: ""
category: Programs
tags: [singleton, c++, template]
---
{% include JB/setup %}

## Why?

Singleton is a common and effective design pattern to simplify resource management that is allocated only once during application's lifecycle.

When multiple classes need to be singleton class, it will be tendious to turn them into singleton one by one with almost similar code blocks.

That's a kind of `bad` smell, where template class in C++ comes to help.

## Not perfect yet good enough version

The basic requirements of implementing a singleton includes:

- Make constructors private
- Force instantiate via static public factory method
- Free resources automatically

`Singleton.h`

    #ifndef SINGLETON_H
    #define SINGLETON_H

    #include <cstdlib>

    template <typename T>
    class Singleton
    {
    public:
        static T *instance() {
            if (0 == _instance) {
                _instance = new T();
                atexit(destroy);
            }

            return _instance;
        }

        static void destroy() {
            delete _instance;
        }

    private:
        Singleton();
        ~Singleton();
        Singleton(const Singleton &/*other*/);
        Singleton &operator=(const Singleton &/*other*/);

    private:
        static T *_instance;
    };

    template <typename T>
    T *Singleton<T>::_instance = 0;

    #define DEFINE_SINGLETON(classname) \
    typedef Singleton<classname> classname##_st;

    #endif // SINGLETON_H

Then we can use that in our own class that is meant to be singleton.

`Test.h`

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

And source file is as following.

`Test.cpp`

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

Let's test them with a `main` entry.

`Main.cpp`

    #include <iostream>

    #include "Test.h"

    int main(int argc, char *argv[])
    {
        std::cout << "Without Singleton Pattern" << std::endl;
        Test().run();
        Test().run();

        std::cout << "Using Singleton Pattern" << std::endl;
        Singleton<Test>::instance()->run();
        Test_st::instance()->run();
    }

For my preference, I use `scons` for compiling above codes into `singleton-test` binary with following script.

`SConstruct`

    env = Environment()
    env.Program(target = 'singleton-test', source = Glob('*.cpp'))

The building process prints following output, if you care:

    $ scons
    scons: Reading SConscript files ...
    scons: done reading SConscript files.
    scons: Building targets ...
    g++ -o Main.o -c Main.cpp
    g++ -o Test.o -c Test.cpp
    g++ -o singleton-test Main.o Test.o
    scons: done building targets.

As expected, we get following results:

    $ ./singleton-test
    Without Singleton Pattern
    Test()
    run()
    ~Test()
    Test()
    run()
    ~Test()

    Using Singleton Pattern
    Test()
    run()
    run()
    ~Test()

Without singleton feature, multiple instances are generated, only one is reused otherwise.

## Remarks

Test class can also have a super class. Also works without any problems, at least for now, with Qt framework's signals and slots.

Following aspects are to be improved:

- Cross DLL re-initialization
- Multi-thread re-entrant
