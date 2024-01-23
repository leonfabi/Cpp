/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 16:20:41 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	// DiamondTrap	one("Fabian");
	// DiamondTrap	two(one);

	// two.whoAmI();
	// one.guardGate();
	// one.highFivesGuys();
  DiamondTrap Trap("Frank");
  Trap.print();
  Trap.attack("Trash");
  Trap.ClapTrap::attack("Nothing");
  Trap.beRepaired(0);
  Trap.takeDamage(0);
  Trap.whoAmI();
  Trap.guardGate();
  Trap.highFivesGuys();
  return (0);
}