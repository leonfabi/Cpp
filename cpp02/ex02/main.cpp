/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:23:18 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 15:29:35 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void ) {
	Fixed a(5.05f);
	Fixed b(5);
	Fixed c;
	const Fixed constA(3.5f);
	const Fixed constB(4.2f);


	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	c = a + b;
	std::cout << "a + b: " << c << std::endl;
	c = a - b;
	std::cout << "a - b: " << c << std::endl;
	c = a * b;
	std::cout << "a * b: " << c << std::endl;
	c = a / b;
	std::cout << "a / b: " << c << std::endl;

	std::cout << "b++: " << b++ << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "++b: " << ++b << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "b--: " << b-- << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "--b: " << --b << std::endl;

	std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;

	std::cout << "constA is " << constA << std::endl;
	std::cout << "constB is " << constB << std::endl;
	std::cout << "Const Max(constA, constB): " << Fixed::max(constA, constB) << std::endl;
	std::cout << "Const Min(constA, constB): " << Fixed::min(constA, constB) << std::endl;

	return 0;
}