#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//  Fixed c;
(b + a) = a;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int main() {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << "Initial values:" << std::endl;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;

//     std::cout << "\nTesting increment and decrement operators:" << std::endl;
//     std::cout << "++a = " << ++a << std::endl;
//     std::cout << "a   = " << a << std::endl;
//     std::cout << "a++ = " << a++ << std::endl;
//     std::cout << "a   = " << a << std::endl;
//     std::cout << "--a = " << --a << std::endl;
//     std::cout << "a   = " << a << std::endl;
//     std::cout << "a-- = " << a-- << std::endl;
//     std::cout << "a   = " << a << std::endl;

//     std::cout << "\nTesting arithmetic operators:" << std::endl;
//     Fixed c = Fixed(10) + Fixed(2.5f);
//     Fixed d = Fixed(10) - Fixed(2.5f);
//     Fixed e = Fixed(10) * Fixed(2.5f);
//     Fixed f = Fixed(10) / Fixed(2.5f);
//     std::cout << "10 + 2.5 = " << c << std::endl;
//     std::cout << "10 - 2.5 = " << d << std::endl;
//     std::cout << "10 * 2.5 = " << e << std::endl;
//     std::cout << "10 / 2.5 = " << f << std::endl;

//     std::cout << "\nTesting comparison operators:" << std::endl;
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     std::cout << "\nTesting min and max functions:" << std::endl;
//     std::cout << "Min(a, b) = " << Fixed::min(a, b) << std::endl;
//     std::cout << "Max(a, b) = " << Fixed::max(a, b) << std::endl;

//     return 0;
// }
