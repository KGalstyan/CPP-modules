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
	std::cout << areaABC << std::endl;
	std::cout << areaPAB << std::endl;
	std::cout << areaPBC << std::endl;
	std::cout << areaPCA << std::endl;
	if(areaABC == (areaPAB + areaPBC + areaPCA))
		return(true);
	return (false);
}
