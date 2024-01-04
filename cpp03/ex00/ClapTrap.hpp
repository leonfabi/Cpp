/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:38 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/04 16:55:15 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>


class ClapTrap{
	private:
		std::string	_name;
		int			_hit_p;
		int			_energy_p;
		int			_damage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &old_obj);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap &old_obj);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif