/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:09:17 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/02 15:05:52 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void brain_test(void){
    Cat Mieze;
    Cat Tiger = Mieze;
    Mieze.add_idea("I am so hungry");
    Mieze.add_idea("I want to eat a mouse");
    Mieze.print_brain();
    Tiger = Mieze;
    Tiger.add_idea("I'd rather fancy an Antilope");
    Mieze.add_idea("Or maybe I want to drink some nice warm milk");
    Tiger.print_brain();
    Mieze.print_brain();
    Cat Lion(Tiger);
    Lion.add_idea("Give me something bigger than an Antilope");
    Lion.print_brain();
}

int main()
{
    // Animal test;
    brain_test();
    return 0;
}