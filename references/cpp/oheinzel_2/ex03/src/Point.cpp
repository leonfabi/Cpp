/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:15:13 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 10:15:24y oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: _x(0), _y(0)
{

}

Point::Point(const Point& rhs)
	:_x(rhs._x), _y(rhs._y)
{

}

Point::Point(float const newX, float const newY)
	: _x(newX), _y(newY)
{

}

Point::~Point(void)
{

}

Point&	Point::operator=(const Point& rhs)
{
	(void)rhs;
	return (*this);
}

Fixed const Point::getX(void) const
{
	return (_x);
}
Fixed const Point::getY(void) const
{
	return (_y);
}


