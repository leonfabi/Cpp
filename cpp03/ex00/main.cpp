/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 15:47:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
	ClapTrap	one("one");
	ClapTrap	two(one);
	one.print();
	two.print();
	}
	{
	ClapTrap	one("Fabian");

	one.print();
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
	one.attack("Attack 10");
	}
}