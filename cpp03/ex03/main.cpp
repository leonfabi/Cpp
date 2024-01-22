/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:32:14 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
	DiamondTrap	one("Fabian");
	DiamondTrap	two(one);

	two.whoAmI();
	// two = one;
	// two.whoAmI();
	// one.print();
	// one.attack("two");
	// one.takeDamage(20);
	// one.beRepaired(5);
	// one.print();
	// one.guardGate();
	// one.highFivesGuys();
	// one.whoAmI();
	}
}