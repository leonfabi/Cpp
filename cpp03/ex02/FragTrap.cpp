/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:18:56 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:41:33 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "FragTrap Default constructor called for: " << _name << std::endl;
	_hit_p = 100;
	_energy_p = 100;
	_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "FragTrap Constructor called for: " << _name << std::endl;
	_hit_p = 100;
	_energy_p = 100;
	_damage = 30;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called for: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &old_obj) : ClapTrap(old_obj){
	std::cout << "FragTrap Copy constructor called\n";
	*this = old_obj;
}

FragTrap& FragTrap::operator=(const FragTrap &old_obj){
	std::cout << "FragTrap Copy overload called\n";
	if (this != &old_obj)
		ClapTrap::operator=(old_obj);
	return *this;
}

void FragTrap::highFivesGuys(void) const {
	std::cout << "Hi Guys let's do an awesome HIGH FIVE!!!\n";
}