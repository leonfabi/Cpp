/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:28 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/04 14:24:31 by fkrug            ###   ########.fr       */
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
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif