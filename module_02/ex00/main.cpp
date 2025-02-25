#include "Fixed.hpp"

int main( void )
{
	Fixed a; // Def
	Fixed b( a ); // Copy
	Fixed c; // Def
	c = b; // operator =
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
