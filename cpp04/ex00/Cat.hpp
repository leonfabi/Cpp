/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:26 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 14:20:44 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
    public:
        Cat();
        ~Cat();
        Cat(const Cat &old_obj);
        Cat& operator=(const Cat &old_obj);
        virtual void makeSound(void) const;
};
#endif