/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:28 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 15:15:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
	private:
		int	_fp_value;
		static const int	_fract_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &old_obj);
		Fixed(const int integer);
		Fixed(const float floating_point);

		Fixed& operator=(const Fixed &right);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator+(const Fixed &right);
		Fixed operator-(const Fixed &right);
		Fixed operator*(const Fixed &right);
		Fixed operator/(const Fixed &right);
		bool operator<(const Fixed &right)const;
		bool operator<=(const Fixed &right)const;
		bool operator>(const Fixed &right)const;
		bool operator>=(const Fixed &right)const;
		bool operator==(const Fixed &right)const;
		bool operator!=(const Fixed &right)const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif