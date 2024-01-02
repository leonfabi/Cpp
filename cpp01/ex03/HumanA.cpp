/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 14:23:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string str, Weapon& weapon) : _name(str), _weapon(weapon)
{
}

HumanA::~HumanA(){
}

void HumanA::attack(void)const{
	std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
}