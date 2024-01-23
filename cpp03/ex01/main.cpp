/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 16:04:22 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	one("Fabian");
	ScavTrap	two(one);

	one.print();
	two.print();
	one.attack("Attack 1");
	one.attack("Attack 2");
	one.attack("Attack 3");
	one.attack("Attack 4");
	one.attack("Attack 5");
	one.attack("Attack 6");
	one.attack("Attack 7");
	one.attack("Attack 8");
	one.attack("Attack 9");
	one.beRepaired(5);
	one.print();
	one.takeDamage(20);
	one.print();
	two = one;
	two.print();
	two.guardGate();
}