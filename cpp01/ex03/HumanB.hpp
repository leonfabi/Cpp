/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:57:32 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 14:26:02 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon*	_weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void attack(void)const;
		void setWeapon(Weapon& weapon);
};

#endif