#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <time.h>
#include <pthread.h>

class singleton1
{
    private:
        singleton1();
        ~singleton1();

        static singleton1 *instance;
        static pthread_mutex_t mutex;
        time_t m_pData;

    public:
        static singleton1 * get_instance();
        time_t get_data();
};

#endif
