/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:08:27 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 19:12:09 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal(){
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog(){
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &old_obj):Animal(old_obj){
	std::cout << "Dog copy constructor called\n";
	*this = old_obj;
}

Dog& Dog::operator=(const Dog &old_obj){
	std::cout << "Dog operator overload called\n";
	if (this!=&old_obj)
		type = old_obj.type;
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "Dog noises\n";
}