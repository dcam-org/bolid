#include "BTGenerator.hpp"


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


/*
    TODO (?)
    Calls generate() in separate thread periodically.
*/
void BTGenerator::run(int dt) {

}

