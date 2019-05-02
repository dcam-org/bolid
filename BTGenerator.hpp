#ifndef GN_HPP__ 
#define GN_HPP__


const int DEFAULT_TIME_STEP_VAL = 10000;


#include "BTBolide.hpp"
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


class BTGenerator {
public:
    BTGenerator();
    ~BTGenerator();
    BTGenerator(BTGenerator& ) = delete;
    BTBolideData getData();
    void setData(BTBolideData data);
    void generate();
    void run();
    void stop();
    bool isRunning();
    void setTimeStep(int dt);

private:
    BTBolideData data_;
    int dt_ = DEFAULT_TIME_STEP_VAL;    //microseconds
    bool running_;
    pthread_t Gthread;
    pthread_mutex_t mutex;
    /*
        The only way to pass member function to 'pthread_create(...)'
        is to make it static
    */
    static void* start_routine(void * classPtr);

};


#endif
