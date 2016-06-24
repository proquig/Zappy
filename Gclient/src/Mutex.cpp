#include <Mutex.hh>

Mutex::Mutex()
{
    if ((pthread_mutex_init(&this->_mutex, NULL)) != 0)
    {
        std::cerr << "Error occured while initializing mutex" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Mutex::~Mutex()
{
}

void    Mutex::lock()
{
    if (pthread_mutex_lock(&this->_mutex) != 0)
    {
        std::cerr << "Error occured while locking mutex" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void    Mutex::unlock()
{    
    if (pthread_mutex_unlock(&this->_mutex) != 0)
    {
        std::cerr << "Error occured while unlocking mutex" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void    Mutex::trylock()
{
    if (pthread_mutex_trylock(&this->_mutex))
    {
        std::cerr << "Error occured while trylocking mutex" << std::endl;
        exit(EXIT_FAILURE);
    }
}