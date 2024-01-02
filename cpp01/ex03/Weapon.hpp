/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:42:25 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 13:53:43 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class	Weapon{
	private:
		std::string	type;
	public:
		Weapon(std::string str);
		~Weapon();
		const std::string& getType(void);
		void setType(std::string str);
};

#endif