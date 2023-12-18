/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:50:39 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 09:36:30 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int	_val;
		static const int	_fract;

	public:
		Fixed(void);
		Fixed(const Fixed &rhs);
		Fixed(int newVal);
		Fixed(float newVal);
		~Fixed(void);
		Fixed& operator=(const Fixed &rhs);
		int toInt(void) const;
		float toFloat(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &rhs);

#endif
