/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:41:24 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 11:45:16 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(){
	FragTrap::_hitpoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "\033[1;32mDiamondTrap Default Constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name_(name){
	std::cout << "\033[1;32mDiamondTrap Constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref._name_ + "_clap_name"), ScavTrap(), FragTrap(), _name_(ref._name_){
	std::cout << "\033[1;32mDiamondTrap Copy Constructor called\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "\033[1;31mDiamondTrap Destructor called\033[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& ref){
	std::cout << "\033[1;33mDiamondTrap Assignation Operator called\033[0m" << std::endl;
	if (this == &ref)
		return (*this);
	_name_ = ref._name_;
	_hitpoints = ref._hitpoints;
	_energyPoints = ref._energyPoints;
	_attackDamage = ref._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "My name is " << _name_ << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
