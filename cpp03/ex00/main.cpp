/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:09 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 12:00:44 by fkrug            ###   ########.fr       */
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
	one.attack("two");
	one.takeDamage(20);
	one.beRepaired(5);
	one.print();

	}
}