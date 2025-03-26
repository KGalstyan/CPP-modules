#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed()
{
	setRawBits(0);
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	setRawBits(roundf(value *(1 << this->number_fractional_bits)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	setRawBits(value << this->number_fractional_bits);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	// std::cout << "Copy constructor called" << std::endl;
	(*this) = a;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return(*this);
	this->fixed_point_number = obj.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &obj)
{
	if(this->fixed_point_number > obj.fixed_point_number)
		return(true);
	else
		return(false);
}

bool Fixed::operator<(const Fixed &obj)
{
	if(this->fixed_point_number < obj.fixed_point_number)
		return(true);
	else
		return(false);
}

bool Fixed::operator>=(const Fixed &obj)
{
	if(this->fixed_point_number >= obj.fixed_point_number)
		return(true);
	else
		return(false);
}

bool Fixed::operator<=(const Fixed &obj)
{
	if(this->fixed_point_number <= obj.fixed_point_number)
		return(true);
	else
		return(false);
}

bool Fixed::operator==(const Fixed &obj)
{
	if(this->fixed_point_number == obj.fixed_point_number)
		return(true);
	else
		return(false);
}

bool Fixed::operator!=(const Fixed &obj)
{
	if(this->fixed_point_number != obj.fixed_point_number)
		return(true);
	else
		return(false);
}

const Fixed Fixed::operator+(const Fixed &obj)
{
	return Fixed((this->toFloat() + obj.toFloat()));
}

const Fixed Fixed::operator-(const Fixed &obj)
{
	return Fixed((this->toFloat() - obj.toFloat()));
}

const Fixed Fixed::operator*(const Fixed &obj)
{
	return Fixed((this->toFloat() * obj.toFloat()));
}

const Fixed Fixed::operator/(const Fixed &obj)
{
	if(obj.fixed_point_number == 0)
	{
		std::cout << "You cannot divide a number by zero" << std::endl;
	}
	return Fixed((this->toFloat() / obj.toFloat()));
}

Fixed& Fixed::operator++()
{

    this->fixed_point_number += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->fixed_point_number -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_point_number += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_point_number -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a.getRawBits() > b.getRawBits())
		return(b);
	return(a);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a.getRawBits() > b.getRawBits())
		return(b);
	return(a);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a.getRawBits() > b.getRawBits())
		return(a);
	return(b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a.getRawBits() > b.getRawBits())
		return(a);
	return(b);
}

int Fixed::toInt( void ) const
{
	return(this->fixed_point_number >> this->number_fractional_bits);
}

float Fixed::toFloat( void ) const
{
	return((float)this->fixed_point_number / (1 << this->number_fractional_bits));
}

int Fixed::getRawBits( void ) const
{
	return(this->fixed_point_number);
}

void  Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
