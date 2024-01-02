/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:48:01 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 13:53:39 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type(str){
}

Weapon::~Weapon(){
}

const std::string& Weapon::getType(void){
	return (type);
}

void Weapon::setType(std::string str){
	type = str;
}