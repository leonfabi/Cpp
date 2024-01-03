/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:48:34 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/03 13:20:37 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>
#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(void){
	std::cout << DEBUG << std::endl;
}

void Harl::info(void){
	std::cout << INFO << std::endl;
}

void Harl::warning(void){
	std::cout << WARNING << std::endl;
}

void Harl::error(void){
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level){
	std::map<std::string, HarlMemFn>	mapping;
	mapping["debug"] = &Harl::debug;
	mapping["info"] = &Harl::info;
	mapping["warning"] = &Harl::warning;
	mapping["error"] = &Harl::error;
	HarlMemFn	fn = mapping[level];
	if (fn)
		(this->*fn)();
	else
		std::cerr << "Error wrong level" << std::endl;
}