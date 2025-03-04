#include "Point.hpp"

Point::Point(): x(0) , y(0)
{
}

Point::~Point()
{
}

Point::Point(const float x, const float y): x(x) , y(y)
{
}

Point::Point(const Point &a): x(a.x) , y(a.y)
{
	(*this) = a;
}

Point& Point::operator=(const Point &obj)
{
	if (this == &obj)
		return(*this);
	return(*this);
}

float Point::getX(void) const
{
	return(x.toFloat());
}
float Point::getY(void) const
{
	return(y.toFloat());
}
