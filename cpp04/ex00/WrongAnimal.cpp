/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:52:25 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 13:55:47 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &old_obj){
    std::cout << "WrongAnimal copy constructor called\n";
    *this = old_obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &old_obj){
    std::cout << "WrongAnimal operator overload called\n";
    if (this!=&old_obj)
        type = old_obj.type;
    return *this;
}

void    WrongAnimal::makeSound(void) const{
    std::cout << "WrongUndefined noises\n";
}

std::string WrongAnimal::getType(void) const{
    return type;
}