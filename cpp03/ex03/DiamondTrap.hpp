/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:10:10 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:06:28 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap {
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