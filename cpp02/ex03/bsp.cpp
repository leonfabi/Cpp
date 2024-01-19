/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:08 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/12 14:52:36 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int orientation(Point const a, Point const b, Point const c){
	Point AB(b.getx() - a.getx(), b.gety() - a.gety());
	Point AC(c.getx() - a.getx(), c.gety() - a.gety());
	float cross_product = AB.getx() * AC.gety() - AB.gety() * AC.getx();
	if (cross_product > 0)
		return 1;
	else if (cross_product < 0)
		return -1;
	else
		return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	int sum = orientation(a, b, point) + orientation(b, c, point) + orientation(c, a, point);
	if (sum == 3 || sum == -3)
		return true;
	else
		return false;
}