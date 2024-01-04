/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:57:05 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/04 14:20:00 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp_value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &old_obj): _fp_value(old_obj._fp_value){
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed &right){
	if (this != &right)
		_fp_value = right._fp_value;
	return (*this);
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (_fp_value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fp_value = raw;
}