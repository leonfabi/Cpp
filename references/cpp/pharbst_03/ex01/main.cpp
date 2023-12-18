/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:09:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/23 18:21:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void){
	ScavTrap	crapTrap("CrapTrap");
	ScavTrap	scrapTrap;

	scrapTrap = crapTrap;

	std::cout << std::endl;
	scrapTrap.attack();
	scrapTrap.takeDamage(5);
	scrapTrap.beRepaired(5);
	scrapTrap.guardGate();
	std::cout << std::endl;
	return 0;
}
