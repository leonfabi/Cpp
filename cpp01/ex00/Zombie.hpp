/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:58 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 09:06:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string str);
		void	announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif