/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:06:35 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 15:33:49 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
    private:
        Brain*  _brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &old_obj);
        Dog& operator=(const Dog &old_obj);
        virtual void makeSound(void) const;
        void add_idea(std::string idea);
        void print_brain(void) const;
};
#endif