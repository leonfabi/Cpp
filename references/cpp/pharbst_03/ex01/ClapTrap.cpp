/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:02:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 11:39:22 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitpoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "\033[0;32mDefault Constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "\033[0;32mConstructor called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "\033[1;31mDestructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref){
	std::cout << "\033[0;32mCopy Constructor called\033[0m" << std::endl;
	*this = ref;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& ref){
	std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	_name = ref._name;
	_hitpoints = ref._hitpoints;
	_energyPoints = ref._energyPoints;
	_attackDamage = ref._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (_energyPoints <= 0){
		std::cout << "\033[0;31mClapTrap " << _name << " can't attack, it's out of energy!\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;33mClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitpoints - amount <= 0){
		std::cout << "\033[0;31mClapTrap " << _name << " takes " << _hitpoints << " points of damage and dies!\033[0m" << std::endl;
		_hitpoints = 0;
		return ;
	}
	std::cout << "\033[0;33mClapTrap " << _name << " takes " << amount << " points of damage!\033[0m" << std::endl;
	_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitpoints <= 0)
		std::cout << "\033[0;31mClapTrap " << _name << " can't be repaired, it's dead!\033[0m" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "\033[0;31mClapTrap " << _name << " can't be repaired, it's out of energy!\033[0m" << std::endl;
	else{
		std::cout << "\033[0;33mClapTrap " << _name << " is repaired for " << amount << " points of damage!\033[0m" << std::endl;
		_energyPoints--;
		_hitpoints += amount;
	}
}
