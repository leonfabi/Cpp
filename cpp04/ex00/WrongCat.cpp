/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:50 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/23 13:56:41 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(){
	std::cout << "WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat &old_obj):WrongAnimal(old_obj){
	std::cout << "WrongCat copy constructor called\n";
	*this = old_obj;
}

WrongCat& WrongCat::operator=(const WrongCat &old_obj){
	std::cout << "WrongCat operator overload called\n";
	if (this!=&old_obj)
		type = old_obj.type;
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "WrongCat noises\n";
}