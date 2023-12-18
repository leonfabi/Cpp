/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:09:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/23 19:05:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void){
	FragTrap	crapTrap("CrapTrap");
	FragTrap	scrapTrap;

	scrapTrap = crapTrap;

	std::cout << std::endl;
	scrapTrap.attack();
	scrapTrap.takeDamage(5);
	scrapTrap.beRepaired(5);
	scrapTrap.highFivesGuys();
	std::cout << std::endl;
	return 0;
}
