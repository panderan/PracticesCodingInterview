#include "singleton1.h"

singleton1* singleton1::instance = NULL;
pthread_mutex_t singleton1::mutex = PTHREAD_MUTEX_INITIALIZER;

singleton1::singleton1()
{
    m_pData = time(NULL);
}

singleton1 * singleton1::get_instance()
{
    if (instance == NULL) {
        pthread_mutex_lock(&mutex);
        if (instance == NULL) {
            instance = new singleton1();
        }
        pthread_mutex_unlock(&mutex);
    }

    return instance;
}

time_t singleton1::get_data()
{
    return m_pData;
}
