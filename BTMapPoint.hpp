#pragma once


class BTMapPoint
{
public:
	float getX() const;
	float getY() const;
	float getCurvRadius() const;

private:
	float m_x;
	float m_y;
	float m_curvRadius;
};