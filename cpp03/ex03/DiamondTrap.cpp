/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:18:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 14:56:57 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), ScavTrap(), FragTrap(){
	_name = ClapTrap::_name;
	std::cout << "DiamondTrap Default constructor called for: " << _name << std::endl;
	_energy_p = ScavTrap::_energy_p;
	_hit_p = FragTrap::_hit_p;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
	_name = ClapTrap::_name;
	std::cout << "DiamondTrap Default constructor called for: " << _name << std::endl;
	_energy_p = ScavTrap::_energy_p;
	_hit_p = FragTrap::_hit_p;
	_damage = FragTrap::_damage;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor called for: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &old_obj) : ClapTrap(old_obj){
	std::cout << "DiamondTrap Copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &old_obj){
	std::cout << "DiamondTrap Copy overload called\n";
	if (this != &old_obj)
		ClapTrap::operator=(old_obj);
	return *this;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(name);
}

void DiamondTrap::whoAmI(void) const{
	std::cout << "My DiamondTrap name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}