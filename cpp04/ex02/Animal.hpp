/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:46:46 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 16:37:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
    protected:
        std::string    type;
        Animal();
    public:
        virtual ~Animal();
        Animal(const Animal &old_obj);
        Animal& operator=(const Animal &old_obj);

        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
};
#endif