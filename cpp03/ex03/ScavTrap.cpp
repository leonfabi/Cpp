/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:18:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 16:22:26 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap Default constructor called for: " << _name << std::endl;
	_hit_p = 100;
	_energy_p = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "ScavTrap Constructor called for: " << _name << std::endl;
	_hit_p = 100;
	_energy_p = 50;
	_damage = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called for: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &old_obj) : ClapTrap(old_obj){
	std::cout << "ScavTrap Copy constructor called\n";
	*this = old_obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &old_obj){
	std::cout << "ScavTrap Copy overload called\n";
	if (this != &old_obj)
		ClapTrap::operator=(old_obj);
	return *this;
}

void ScavTrap::guardGate(void) const{
	std::cout << "ScavTrap " << _name << " is now in guard mode\n";
}

void ScavTrap::attack(const std::string& target){
	std::cout << "ScavTrap Attack function\n";
	if (!_energy_p){
		std::cout << "ScavTrap " << _name << " has no energy points left\n";
		return ;
	}else if (!_hit_p){
		std::cout << "ScavTrap " << _name << " has no hit points left\n";
		return ;
	}else{
		_energy_p--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n";
	}
}