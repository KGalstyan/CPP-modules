#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &a);
		Fixed& operator=(const Fixed &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fixed_point_number;
		static const int number_fractional_bits;
};

#endif
