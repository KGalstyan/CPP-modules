#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float x, float y);
		Point(const Point &a);
		Point& operator=(const Point &obj);
		~Point();

		float getX(void) const;
		float getY(void) const;
	private:
		const Fixed x;
		const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


