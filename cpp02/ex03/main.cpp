/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:23:18 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/19 17:01:47 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {
	Point A(0,0);
	Point B(5,0);
	Point C(0,5);

	Point P(0,1);
	std::cout << "Point P(" << P.getx() << "," << P.gety() << "): " << bsp(A,B,C,P) << std::endl;
	return 0;
}