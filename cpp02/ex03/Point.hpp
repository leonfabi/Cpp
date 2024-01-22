/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:32:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/12 14:21:24 by fkrug            ###   ########.fr       */
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
		float getx() const;
		float gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif