/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:03 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/01 21:27:56 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
    std::cout << "Cure default constructor called\n";
}

Cure::~Cure(){
    std::cout << "Cure destructor called\n";
}

Cure::Cure(const Cure &old_obj): AMateria(old_obj){
}

Cure& Cure::operator=(const Cure &old_obj){
    (void)old_obj;
    return *this;
}

AMateria* Cure::clone() const{
    return new Cure();
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds*\n";
}