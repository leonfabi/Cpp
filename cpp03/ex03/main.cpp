/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:02:00 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
	DiamondTrap	one("Fabian");

	one.FragTrap::print();
	one.attack("two");
	one.FragTrap::takeDamage(20);
	one.ScavTrap::beRepaired(5);
	one.ScavTrap::print();
	one.guardGate();
	one.highFivesGuys();
	one.whoAmI();
	}
}