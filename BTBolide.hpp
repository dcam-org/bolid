#ifndef __BTBolide
#define __BTBolide


#include <string>


struct BTWheel {
    float pressure, temperature, m_hp;
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

struct BTVec2f {
    float x, y;
};

struct BTWheelSet {
    BTWheel lFront, rFront, 
            lBack, rBack;
};

struct BTPedalSet {
    float gas, stop;
};


class BTBolideData {
public:
    //get
    BTWheelSet getWheels() const {
        return m_wheels;
    }
    BTPedalSet getPedals() const {
        return m_pedals;
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
    float getVelocity() const {
        return m_velocity;
    }
    float getAcceleration() const {
        return m_acceleration;
    }

    //set
    void setWheels(BTWheelSet whls) {
        m_wheels = whls;
    }
    void setPedal(BTPedalSet pdls) {
        m_pedals = pdls;
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
    void setVelocity(float vlst) {
        m_velocity = vlst;
    }
    void setAcceleration(float acc) {
        m_acceleration = acc;
    }

private:
    BTWheelSet m_wheels;
    BTBattery  m_battery;
    BTBreaks   m_breaks;
    BTPedalSet m_pedals;

    BTVec2 m_pos;
    BTVec2 m_speed;
    float  m_time;
    float  m_velocity;
    float  m_acceleration;

};


#endif
