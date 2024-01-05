/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:23:18 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 14:52:12 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void ) {
	Fixed a(5.05f);
	Fixed b(2);
	Fixed c;

	std::cout << "a is " << a << '\n';
	std::cout << "b is " << b << '\n';

	// Test comparison operators
	std::cout << "a > b: " << (a > b) << '\n';
	std::cout << "a < b: " << (a < b) << '\n';
	std::cout << "a >= b: " << (a >= b) << '\n';
	std::cout << "a <= b: " << (a <= b) << '\n';
	std::cout << "a == b: " << (a == b) << '\n';
	std::cout << "a != b: " << (a != b) << '\n';

	// Test arithmetic operators
	c = a + b;
	std::cout << "a + b: " << c << '\n';

	c = a - b;
	std::cout << "a - b: " << c << '\n';

	c = a * b;
	std::cout << "a * b: " << c << '\n';

	c = a / b;
	std::cout << "a / b: " << c << '\n';

	
	// Test increment/decrement
	std::cout << "b++: " << b++ << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "++b: " << ++b << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "b--: " << b-- << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "--b: " << --b << '\n';

	// // Test max and min
	// std::cout << "Max(a, b): " << Fixed::max(a, b) << '\n';
	// std::cout << "Min(a, b): " << Fixed::min(a, b) << '\n';

	return 0;
}