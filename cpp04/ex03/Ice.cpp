/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:04:18 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/30 18:34:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
    std::cout << "Ice default constructor called\n";
}

Ice::~Ice(){
    std::cout << "Ice destructor called\n";
}

Ice::Ice(const Ice &old_obj){
    *this = old_obj;
}

Ice& Ice::operator=(const Ice &old_obj){
    (void)old_obj;
    return *this;
}

AMateria* Ice::clone() const{
    return new Ice();
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}