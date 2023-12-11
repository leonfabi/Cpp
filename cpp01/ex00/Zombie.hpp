/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:58 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 16:00:54 by fkrug            ###   ########.fr       */
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
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif