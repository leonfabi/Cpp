/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:57:05 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/04 16:37:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp_value(0){}
// Fixed::Fixed(const Fixed &old_obj) : _fp_value(old_obj._fp_value) {}
Fixed::Fixed(const Fixed &old_obj){	*this = old_obj;}

Fixed::Fixed(const int integer): _fp_value(integer << _fract_bits){}

Fixed::Fixed(const float floating_point): _fp_value(roundf(floating_point * (1 << _fract_bits))){}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed &right){
	if (this != &right)
		_fp_value = right._fp_value;
	return (*this);
}

bool Fixed::operator<(const Fixed &right) const {	return (_fp_value < right._fp_value); }
bool Fixed::operator>(const Fixed &right) const {	return (right < *this); }
bool Fixed::operator<=(const Fixed &right) const {	return (!(*this > right)); }
bool Fixed::operator>=(const Fixed &right) const {	return (!(*this < right)); }
bool Fixed::operator==(const Fixed &right) const {	return (_fp_value == right._fp_value); }
bool Fixed::operator!=(const Fixed &right) const {	return (!(*this == right)); }

Fixed Fixed::operator+(const Fixed &right){	return (Fixed(toFloat() + right.toFloat())); }
Fixed Fixed::operator-(const Fixed &right){	return (Fixed(toFloat() - right.toFloat())); }
Fixed Fixed::operator*(const Fixed &right){	return (Fixed(toFloat() * right.toFloat())); }
Fixed Fixed::operator/(const Fixed &right){	return (Fixed(toFloat() / right.toFloat())); }

std::ostream& operator<<(std::ostream &out, const Fixed &obj){
	out << obj.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (_fp_value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fp_value = raw;
}

float Fixed::toFloat(void) const{
	return (static_cast<float>(_fp_value) / (1 << _fract_bits));
}

int Fixed::toInt(void) const{
	return (_fp_value >> _fract_bits);
}