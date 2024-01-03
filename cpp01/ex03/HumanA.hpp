/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:55:15 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/03 13:40:40 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA {
	private:
		std::string	_name;
		Weapon&	_weapon;
	public:
		HumanA(std::string str, Weapon& weapon);
		~HumanA();
		void attack(void)const;
};

#endif