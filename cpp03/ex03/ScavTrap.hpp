/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:08:55 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:18:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap{
	public:
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &old_obj);
		ScavTrap& operator=(const ScavTrap &old_obj);
		void attack(const std::string& target);
		void guardGate(void) const;
};