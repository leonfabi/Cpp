/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:32:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 15:38:04 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point& old);
		Point& operator=(const Point& right);
};

#endif