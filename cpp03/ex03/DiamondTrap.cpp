/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:18:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 17:17:31 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(){
	_name = ClapTrap::_name + "_clap_name";
	std::cout << "DiamondTrap Default constructor called for: " << _name << std::endl;
	_energy_p = ScavTrap::_energy_p;
	_hit_p = FragTrap::_hit_p;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name){
	ClapTrap::_name = name + "_clap_name";
	_name = name;
	std::cout << "DiamondTrap Default constructor called for: " << _name << std::endl;
	this->_energy_p = ScavTrap::_energy_p;
	this->_hit_p = FragTrap::_hit_p;
	_damage = FragTrap::_damage;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor called for: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &old_obj) : ClapTrap(old_obj), FragTrap(old_obj), ScavTrap(old_obj){
	std::cout << "DiamondTrap Copy constructor called\n";
	*this = old_obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &old_obj){
	std::cout << "DiamondTrap Copy overload called\n";
	if (this != &old_obj)
	{
		_name = old_obj._name;
		_energy_p = old_obj.ScavTrap::_energy_p;
		_hit_p = old_obj.FragTrap::_hit_p;
		_damage = old_obj.FragTrap::_damage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const{
	std::cout << "My DiamondTrap name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}