/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:09:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/24 12:46:25 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){
	DiamondTrap a("Diamond");
	a.attack();
	a.takeDamage(10);
	a.beRepaired(10);
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
	return 0;
}
