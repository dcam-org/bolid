#pragma once
#include "BTMapPoint.hpp"
#include <vector>


class BTMap
{
public:
	std::vector<BTMapPoint> getPoints() const;
	
private:
	std::vector<BTMapPoint> m_points; 
};