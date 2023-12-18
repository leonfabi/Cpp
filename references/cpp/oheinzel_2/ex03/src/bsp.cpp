/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:08:51 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 21:38:35 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool spd(Point const a, Point const b, Point const c, Point const point)
{
	Point v1 = Point(a.getX().toFloat() - b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat());
	Point v2 = Point(a.getX().toFloat() - c.getX().toFloat(), a.getY().toFloat() - c.getY().toFloat());
	Point v3 = Point(b.getX().toFloat() - c.getX().toFloat(), b.getY().toFloat() - c.getY().toFloat());

	if ((a.getX() - point.getX()) * v1.getY() -
		(a.getY() - point.getY()) * v1.getX() == 0)
		return (false);
	if ((a.getX() - point.getX()) * v2.getY() -
		(a.getY() - point.getY()) * v2.getX() == 0)
		return (false);
	if ((b.getX() - point.getX()) * v3.getY() -
		(b.getY() - point.getY()) * v3.getX() == 0)
		return (false);
	return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed s;
	Fixed t;
	Fixed d;

	if (!spd(a, b, c, point))
		return (false);
	s = ((a.getX() - c.getX()) * (point.getY() - c.getY())) -
		((a.getY() - c.getY()) * (point.getX() - c.getX()));
	t = ((b.getX() - a.getX()) * (point.getY() - a.getY())) -
		((b.getY() - a.getY()) * (point.getX() - a.getX()));
	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return (false);
	d = ((c.getX() - b.getX()) * (point.getY() - b.getY())) -
		((c.getY() - b.getY()) * (point.getX() - b.getX()));
	return (d == 0 || (d < 0) == (s + t <= 0));
}
