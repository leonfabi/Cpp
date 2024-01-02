/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:58 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 12:34:28 by fkrug            ###   ########.fr       */
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
		void	set_name(std::string str);
};

Zombie*	zombieHorde(int N, std::string name);
#endif