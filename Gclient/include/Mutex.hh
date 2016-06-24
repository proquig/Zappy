#ifndef MUTEX_HH_
# define MUTEX_HH_

#include <pthread.h>
#include <unistd.h>
#include <iostream>

class   Mutex
{
    pthread_mutex_t     _mutex;
public:
    Mutex();
    ~Mutex();
    void    lock();
    void    unlock();
    void    trylock();
};

#endif