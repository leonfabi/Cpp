/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:22 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 15:54:06 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hit_p(10), _energy_p(10), _damage(0) {
	std::cout << "ClapTrap Default constructor called for: " << _name << std::endl;
	}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_p(10), _energy_p(10), _damage(0) {
	std::cout << "ClapTrap Constructor called for: " << _name << std::endl;
	}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called for:" << _name << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap &old_obj) {
	if (this != &old_obj){
		_name = old_obj._name;
		_hit_p = old_obj._hit_p;
		_energy_p = old_obj._energy_p;
		_damage = old_obj._damage;
		std::cout << "ClapTrap Copy overload called\n";
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &old_obj){
	std::cout << "ClapTrap Copy constructor called\n";
	*this = old_obj;
}

void ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap Attack function\n";
	if (!_energy_p){
		std::cout << "ClapTrap " << _name << " has no energy points left\n";
		return ;
	}else if (!_hit_p){
		std::cout << "ClapTrap " << _name << " has no hit points left\n";
		return ;
	}else{
		_energy_p--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap takeDamage called\n";
	if (amount >= _hit_p){
		std::cout << "ClapTrap " << _name << " takes " << _hit_p << " points of damage\n";
		_hit_p = 0;
	}
	else{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage\n";
		_hit_p -= amount;
	}
	if (_hit_p > 0){
		std::cout << "ClapTrap " << _name << " has " << _hit_p << " left\n";
	}else{
		std::cout << "ClapTrap " << _name << " has not hit_points left\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "ClapTrap beRepared called\n";
	if (!_energy_p){
		std::cout << "ClapTrap  " << _name << " has no energy points left\n";
		return ;
	}
	_energy_p--;
	_hit_p += amount;
	std::cout << "ClapTrap " << _name << " recovered " << amount << " hitpoints\n";
}

void ClapTrap::print(void) const{
	std::cout << "INFO#######################################################################" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hit_p << std::endl;
	std::cout << "Energy Points: " << _energy_p << std::endl;
	std::cout << "Attack Damage: " << _damage << std::endl;
	std::cout << "END#######################################################################" << std::endl;
}