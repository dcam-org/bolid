#pragma once
#include <string>
#include "BTBolide.hpp"
#include "BTMap.hpp"

class BTSimulator {
public:
    //get
    BTMapPoint * getPoint() const {
        return m_currentPoint;
    }
    BTMap * getMap() const {
        return m_map;
    }
    BTBolideData * getData() const {
        return m_data;
    }

    //set
    void setPoint(BTMapPoint * pnt) {
        m_currentPoint = pnt;
    }
    void setMap(BTMap * mp) {
        m_map = mp;
    }
    void setData(BTBolideData * dt) {
        m_data = dt;
    }
    
    void engine_step();
    void racer_step();
    void run();

private:
    BTMapPoint *m_currentPoint;
	BTMap *m_map;
	BTBolideData *m_data;
	bool m_on_pitstop;
	float m_pilot_craziness_level;
	int m_current_pit;
	int m_current_lap;
};


