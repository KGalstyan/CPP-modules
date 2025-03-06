#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const float value);
		Fixed(const int value);
		~Fixed();
		Fixed(const Fixed &a);

		Fixed& operator=(const Fixed &obj);

		bool operator>(const Fixed &obj);
		bool operator<(const Fixed &obj);
		bool operator>=(const Fixed &obj);
		bool operator<=(const Fixed &obj);
		bool operator==(const Fixed &obj);
		bool operator!=(const Fixed &obj);

		const Fixed operator+(const Fixed &obj);
		const Fixed operator-(const Fixed &obj);
		const Fixed operator*(const Fixed &obj);
		const Fixed operator/(const Fixed &obj);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fixed_point_number;
		static const int number_fractional_bits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
