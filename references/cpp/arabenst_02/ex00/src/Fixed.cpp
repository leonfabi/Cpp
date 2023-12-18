/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:59 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/11 10:05:08 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

using std::clog;
using std::endl;

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed(void) : _raw(0) {
	clog << "\033[2mDefault constructor called\033[0m" << endl;
}

Fixed::Fixed(const Fixed &other) {
	clog << "\033[2mCopy constructor called\033[0m" << endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	clog << "\033[2mCopy assignment operator called\033[0m" << endl;
	_raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	clog << "\033[2mDestructor called\033[0m" << endl;
}

int Fixed::getRawBits(void) const {
	clog << "\033[2mgetRawBits member function called\033[0m" << endl;
	return (_raw);
}

void Fixed::setRawBits(const int raw) {
	clog << "\033[2msetRawBits member function called\033[0m" << endl;
	_raw = raw;
}
