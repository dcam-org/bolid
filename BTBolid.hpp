#ifndef __BTBOLID
#define __BTBOLID


#include <string>


const int BT_WHEELS_COUNT = 4;

const int LEFT_TOP_WHEEL = 0;
const int RIGHT_TOP_WHEEL = 1;
const int LEFT_BOT_WHEEL = 2;
const int RIGHT_BOT_WHEEL = 3;


struct BTWheel {
    float pressure, temperature;
};

struct BTBattery {
    float voltage, charge;
};

struct BTBreaks {
    float disk_temperature, disk_intensity, 
          fluid_temperature, fluid_intencity;
};

struct BTVec2 {
    int x, y;
};

struct BTWheelSet {
    BTWheel lFront, rFront, 
            lBack, rBack;
};


class BTBolidData {
public:
    //get
    BTWheelSet getWheels() const {
        return m_wheels;
    }

    BTBattery getBattery() const {
        return m_battery;
    }
    BTBreaks getBreaks() const {
        return m_breaks;
    }
    BTVec2 getPos() const {
        return m_pos;
    }
    BTVec2 getSpeed() const {
        return m_speed;
    }
    float getTime() const {
        return m_time;
    }

    //set
    void setWheels(BTWheelSet whls) {
        m_wheels = whls;
    }

    void setBattery(BTBattery bt) {
        m_battery = bt;
    }
    void setBreaks(BTBreaks br) {
        m_breaks = br;
    }
    void setPos(BTVec2 pos) {
        m_pos = pos;
    }
    void setSpeed(BTVec2 spd) {
        m_speed = spd;
    }
    void setTime(float t) {
        m_time = t;
    }

private:
    BTWheelSet m_wheels;
    BTBattery m_battery;
    BTBreaks m_breaks;

    BTVec2 m_pos;
    BTVec2 m_speed;
    float m_time;
};


#endif