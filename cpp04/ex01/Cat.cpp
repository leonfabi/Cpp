/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:50 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 16:07:50 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal(){
    std::cout << "Cat default constructor called\n";
    type = "Cat";
    _brain = new Brain();
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
    delete _brain;
}

Cat::Cat(const Cat &old_obj):Animal(old_obj){
    _brain = new Brain(*old_obj._brain);
    *this = old_obj;
}

Cat& Cat::operator=(const Cat &old_obj){
    if (this!=&old_obj){
        type = old_obj.type;
        *_brain = *(old_obj._brain);
    }
    return *this;
}

void    Cat::makeSound(void) const{
    std::cout << "Cat noises\n";
}

void    Cat::add_idea(std::string idea){
    _brain->add_idea(idea);
}

void    Cat::print_brain(void) const{
    _brain->print_brain();
}