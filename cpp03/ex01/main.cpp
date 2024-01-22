/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 12:44:26 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
	ScavTrap	one("one");
	ScavTrap	two;

	two = one;
	}
	{
	ScavTrap	one("Fabian");


	one.print();
	one.attack("two");
	one.takeDamage(20);
	one.beRepaired(5);
	one.print();
	one.guardGate();

	}
}