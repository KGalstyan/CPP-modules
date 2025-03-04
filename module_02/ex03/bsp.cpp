#include "Point.hpp"

Fixed ft_module(Fixed value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

Fixed count_area(const Point a, const Point b, const Point c)
{
	return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = ft_module(count_area(a, b, c)) / 2;
	Fixed areaPAB = ft_module(count_area(point, a, b)) / 2;
	Fixed areaPBC = ft_module(count_area(point, b, c)) / 2;
	Fixed areaPCA = ft_module(count_area(point, c, a)) / 2;
	if((areaABC == (areaPAB + areaPBC + areaPCA)) && (areaPAB != 0 && areaPBC != 0 && areaPCA != 0))
		return(true);
	return (false);
}
