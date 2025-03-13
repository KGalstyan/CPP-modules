#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed()
{
	setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_number = a.getRawBits();
	// (*this) = a; chi kareli
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return(*this);
	this->fixed_point_number = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixed_point_number);
}

void  Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}
