/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:23:18 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/12 14:53:58 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {
	Point A(0,0);
	Point B(5,0);
	Point C(0,5);
	{
	Point P(1,1);
	std::cout << "Point P(" << P.getx() << "," << P.gety() << "): " << bsp(A,B,C,P) << std::endl;
	}
	{
	Point P(1,0.1f);
	std::cout << "Point P(" << P.getx() << "," << P.gety() << "): " << bsp(A,B,C,P) << std::endl;
	}

	return 0;
}