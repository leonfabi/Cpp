/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:58:14 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 09:28:11 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;
	int	N = 3;

	z = zombieHorde(N, "Test");
	for (int i=0;i<N;i++)
		z[i].announce();
	delete[] z;
	return (0);
}