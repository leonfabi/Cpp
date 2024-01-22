/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:10:10 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 19:25:22 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &old_obj);
		DiamondTrap& operator=(const DiamondTrap &old_obj);
		void attack(const std::string& target);
		void whoAmI(void) const;
};
#endif