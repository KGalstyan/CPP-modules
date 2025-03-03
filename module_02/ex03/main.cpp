#include "Point.hpp"

int main()
{
   	Point a(0, 0), b(5, 0), c(3, 5), p(5, 5);

    if (bsp(a, b, c, p))
        std::cout << "The point is inside the triangle." << std::endl;
	else
        std::cout << "The point is outside the triangle." << std::endl;
    return (0);
}
