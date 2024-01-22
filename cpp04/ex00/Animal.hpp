/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:46:46 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 19:19:16 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
	protected:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &old_obj);
		Animal& operator=(const Animal &old_obj);

		virtual void makeSound(void) const;
		std::string getType(void) const;
};
#endif