/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:42:06 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/02 15:03:49 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain():_position(0){
    std::cout << "Brain default constructor called\n";
}

Brain::~Brain(){
    std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &old_obj){
    *this = old_obj;
}

Brain& Brain::operator=(const Brain &old_obj){
    if (this!=&old_obj){
        _position = old_obj._position;
        for (int i=0; i < 100; i++)
            _ideas[i] = old_obj._ideas[i];
    }
    return *this;
}

void    Brain::add_idea(std::string idea){
    if (_position < MEMORY){
        _ideas[_position] = idea;
        _position++;
    }
}

void    Brain::print_brain(void) const{
    std::cout << "[";
    for (int i=0; i<_position ;i++)
        std::cout << _ideas[i] << ", ";
    std::cout << "]\n";
}