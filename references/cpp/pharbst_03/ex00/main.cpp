/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:03:50 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 16:19:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
	ClapTrap a("The Real ClapTrap");
	ClapTrap b("b");
	ClapTrap c("c");
	
	a.attack("b");
	b.takeDamage(5);
	b.attack("c");
	c.takeDamage(5);
	c.attack("The Real ClapTrap");
	a.takeDamage(5);
	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);
	return (0);
}
