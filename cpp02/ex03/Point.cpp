/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:43 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 15:53:08 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}
Point::~Point() {}
Point::Point(const float x, const float y): _x(0), _y(0) {};
Point::Point(const Point& old) {
		*this = old;
};
Point& Point::operator=(const Point& right){
	(void) right;
	return (*this);
}


