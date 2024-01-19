/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:28 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/19 16:20:13 by fkrug            ###   ########.fr       */
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
		Fixed& operator=(const Fixed &right);
		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif