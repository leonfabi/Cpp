/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:18:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 11:45:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& ref);
		DiamondTrap& operator = (const DiamondTrap& ref);
		~DiamondTrap();

		using	ScavTrap::attack;
		void	whoAmI(void);

	private:
		std::string _name_;
};

#endif