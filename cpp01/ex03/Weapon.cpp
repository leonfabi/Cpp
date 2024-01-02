/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:48:01 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 14:28:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type(str){
}

Weapon::~Weapon(){
}

const std::string& Weapon::getType(void)const{
	return (type);
}

void Weapon::setType(const std::string str){
	type = str;
}