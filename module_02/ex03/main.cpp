#include "Point.hpp"


int main() {

    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.0f);
    Point outside(6.0f, 6.0f);
    Point onEdge(2.5f, 0.0f);

    std::cout << "Inside point: " << (bsp(a, b, c, inside) ? "Inside" : "Outside") << std::endl;
    std::cout << "Outside point: " << (bsp(a, b, c, outside) ? "Inside" : "Outside") << std::endl;
    std::cout << "On edge point: " << (bsp(a, b, c, onEdge) ? "Inside" : "Outside") << std::endl;

    return 0;
}
