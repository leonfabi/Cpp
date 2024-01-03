/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:48:34 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/03 14:46:00 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>
#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(void){
	std::cout << "[DEBUG]\n" << DEBUG << std::endl;
}

void Harl::info(void){
	std::cout << "[INFO]\n"  << INFO << std::endl;
}

void Harl::warning(void){
	std::cout << "[WARNING]\n"  << WARNING << std::endl;
}

void Harl::error(void){
	std::cout << "[ERROR]\n"  << ERROR << std::endl;
}

void Harl::complain(std::string level){
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t	i(0);
	while (i < levels->length() && levels[i].compare(level))
		i++;
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}