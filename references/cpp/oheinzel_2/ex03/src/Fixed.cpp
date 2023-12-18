/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:50:31 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:34 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed::Fixed(void)
	: _val(0)
{
	if (!MUTE)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	if (!MUTE)
		std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed(int newVal)
	: _val(newVal << _fract)
{

}

Fixed::Fixed(float newVal)
	: _val(roundf(newVal * (1 << _fract)))
{

}

Fixed::~Fixed(void)
{
	if (!MUTE)
		std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (!MUTE)
		std::cout << "Copy assignment operator called" << std::endl;
	this->_val = rhs.getRawBits();
	return (*this);
}

int Fixed::toInt(void) const
{
	return (_val >> 8);
}

float Fixed::toFloat(void) const
{
	return ((float)(_val / roundf(1 << _fract)));
}


int Fixed::getRawBits(void) const
{
	if (!MUTE)
		std::cout << "getRawBits member function called" << std::endl;
	return (_val);
}

void Fixed::setRawBits(int const raw)
{
	_val = raw;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_val > rhs._val);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_val < rhs._val);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_val >= rhs._val);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_val <= rhs._val);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_val == rhs._val);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_val != rhs._val);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_val += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed cpy = Fixed(*this);
	this->_val += 1;
	return (cpy);
}

Fixed& Fixed::operator--()
{
	this->_val += 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy = Fixed(*this);
	this->_val -= 1;
	return (cpy);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._val < b._val)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._val > b._val)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._val < b._val)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._val > b._val)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}
