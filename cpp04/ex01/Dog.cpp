/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:08:27 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 16:07:52 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal(){
    std::cout << "Dog default constructor called\n";
    type = "Dog";
    _brain = new Brain();
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
    delete _brain;
}

Dog::Dog(const Dog &old_obj):Animal(old_obj){
    _brain = new Brain(*old_obj._brain);
    *this = old_obj;
}

Dog& Dog::operator=(const Dog &old_obj){
    if (this!=&old_obj)
        type = old_obj.type;
    return *this;
}

void    Dog::makeSound(void) const{
    std::cout << "Dog noises\n";
}

void    Dog::add_idea(std::string idea){
    _brain->add_idea(idea);
}

void    Dog::print_brain(void) const{
    _brain->print_brain();
}