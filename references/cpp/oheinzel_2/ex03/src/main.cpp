/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:16 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 21:37:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

void psb(Point const a, Point const b, Point const c, Point point)
{
	bool res = bsp(a, b, c, point);
	if (!res)
		return ((void)(std::cout << "\033[0;31mpoint not in triangle\033[0m" << std::endl));
	std::cout << "\033[0;32mpoint in triangle\033[0m" << std::endl;
}

int main( void )
{
	Point a(2.0,1.0);
	Point b(1.0,1.0);
	Point c(1.0,2.0);

	psb(a, b, c, Point(1,1));
	psb(a, b, c, Point(1.5f,1));
	psb(a, b, c, Point(1.1f,1.1f));
	psb(b, c, a, Point(1.1f,1.1f));
	psb(a, b, c, Point(10, 10));
	psb(Point(1,1), Point(1,1), Point(1,1), Point(1, 1));
}
