#include "Point.hpp"

Point::Point(): x(0) , y(0)
{
}

Point::~Point()
{
}

Point::Point(float x, float y): x(x) , y(y)
{
	std::cout << x <<std::endl;
	std::cout << y <<std::endl;
}

Point::Point(const Point &a)
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
