/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:48:44 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 11:44:01 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " was destroyed" << std::endl;
}

Zombie::Zombie(std::string str) : name(str)
{
}

void	Zombie::announce(void)const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}