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

#define DEFINE_SINGLETON(classname)	\
typedef Singleton<classname> classname##_st;

#endif // SINGLETON_H
