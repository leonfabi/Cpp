/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:43 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/19 16:59:43 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}
Point::~Point() {}
Point::Point(const float x, const float y): _x(x), _y(y) {};
Point::Point(const Point& old) : _x(old._x), _y(old._y){};
Point& Point::operator=(const Point& right){
	(void) right;
	return (*this);
}

float Point::getx() const{
	return (_x.toFloat());
}

float Point::gety() const{
	return (_y.toFloat());
}