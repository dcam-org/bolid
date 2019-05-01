#include "BTGenerator.hpp"


BTGenerator::BTGenerator() {
    pthread_mutex_init(&mutex, NULL);
}


BTGenerator::~BTGenerator() {
    if (pthread_cancel(Gthread) != ESRCH)
        pthread_join(Gthread, NULL);

    pthread_mutex_destroy(&mutex);
}


void BTGenerator::run() {
    pthread_create(&Gthread, 0, start_routine, this);
}


void BTGenerator::stop() {
    pthread_cancel(Gthread);
    pthread_join(Gthread, NULL);
}


BTBolideData BTGenerator::getData() {
    return data_;
}


void BTGenerator::setData(BTBolideData data) {
    data_ = data;
}


bool BTGenerator::isRunning() {
    return running_;
}


/*
    Calls generate() in separate thread periodically.
    Data modifying procedure is transaction (mutex used).
*/
void* BTGenerator::start_routine(void * classPtr) {
    auto trueClassPtr = static_cast<BTGenerator*>(classPtr);
    /*
        Allows thread to be cancelled immediately.
    */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while(true) {
        pthread_mutex_lock(&trueClassPtr->mutex);
        trueClassPtr->generate();
        pthread_mutex_unlock(&trueClassPtr->mutex);
        usleep(trueClassPtr->dt_);
    }
}


void BTGenerator::setTimeStep(int dt) {
    dt_ = dt; 
}


void BTGenerator::generate() {
    float coef1 = 0.001, 
          coef2 = 0.002, 
          coef3 = 0.0015, 
          coef4 = 0.0025,
          intcoef1 = 2,
          intcoef2 = 3;

    auto tmp_wheels  = data_.getWheels();
    auto tmp_battery = data_.getBattery();
    auto tmp_breaks  = data_.getBreaks();
    auto tmp_pos     = data_.getPos();
    auto tmp_spd     = data_.getSpeed();
    auto tmp_time    = data_.getTime();

    tmp_wheels.lBack.pressure     += coef1;
    tmp_wheels.lBack.temperature  += coef2;
    tmp_wheels.rBack.pressure     += coef3;
    tmp_wheels.rBack.temperature  += coef4;
    tmp_wheels.lFront.pressure    += coef1;
    tmp_wheels.lFront.temperature += coef2;
    tmp_wheels.rFront.pressure    += coef3;
    tmp_wheels.rFront.temperature += coef4;

    tmp_battery.charge  += coef1;
    tmp_battery.voltage += coef3;

    tmp_breaks.disk_intensity    += coef1;
    tmp_breaks.disk_temperature  += coef2;
    tmp_breaks.fluid_intencity   += coef3;
    tmp_breaks.fluid_temperature += coef4;

    tmp_pos.x += intcoef1;
    tmp_pos.y += intcoef2;

    tmp_spd.x += intcoef2;
    tmp_spd.y += intcoef1;

    tmp_time  += coef1;

    data_.setWheels(tmp_wheels);
    data_.setBattery(tmp_battery);
    data_.setBreaks(tmp_breaks);
    data_.setPos(tmp_pos);
    data_.setTime(tmp_time);
}
