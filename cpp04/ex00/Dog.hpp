/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:06:35 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 19:20:46 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog &old_obj);
		Dog& operator=(const Dog &old_obj);
		virtual void makeSound(void) const;
};
#endif