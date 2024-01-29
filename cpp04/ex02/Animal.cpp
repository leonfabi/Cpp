/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:52:25 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 16:37:28 by fkrug            ###   ########.fr       */
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

std::string Animal::getType(void) const{
    return type;
}