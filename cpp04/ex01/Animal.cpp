/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:52:25 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 14:43:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constructor called\n";
}

Animal::~Animal(){
    std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal &old_obj){
    *this = old_obj;
}

Animal& Animal::operator=(const Animal &old_obj){
    if (this!=&old_obj)
        type = old_obj.type;
    return *this;
}

void    Animal::makeSound(void) const{
    std::cout << "Undefined noises\n";
}

std::string Animal::getType(void) const{
    return type;
}