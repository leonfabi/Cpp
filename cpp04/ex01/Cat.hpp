/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:26 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 15:33:45 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    private:
        Brain*  _brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &old_obj);
        Cat& operator=(const Cat &old_obj);
        virtual void makeSound(void) const;
        void add_idea(std::string idea);
        void print_brain(void) const;
};
#endif