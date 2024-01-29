/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:50 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 12:41:12 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal(){
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &old_obj):Animal(old_obj){
	std::cout << "Cat copy constructor called\n";
	*this = old_obj;
}

Cat& Cat::operator=(const Cat &old_obj){
	std::cout << "Cat operator overload called\n";
	if (this!=&old_obj)
		type = old_obj.type;
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "Cat noises\n";
}