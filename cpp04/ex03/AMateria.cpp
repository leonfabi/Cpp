/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:42:02 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/30 18:03:22 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("none"){
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const & type): _type(type){
    std::cout << "AMateria constructor called\n";
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(const AMateria &old_obj){
    *this = old_obj;
}

AMateria& AMateria::operator=(const AMateria &old_obj){
    if (this!=&old_obj)
        _type = old_obj._type;
    return *this;
}

std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    (void) target;
    std::cout << "USE function template called\n";
}