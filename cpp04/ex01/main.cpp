/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:09:17 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 16:09:21 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void animal_array(void){
    int     length = 2;
    Animal*  animals[length];
    for (int i=0;i<length;i++){
        animals[i++] = new Cat();
        animals[i] = new Dog();
    }
    for (int i=0;i<length;i++)
        delete animals[i];
}

void brain_test(void){
    Cat Mieze;
    Cat Tiger;
    Mieze.add_idea("I am so hungry");
    Mieze.add_idea("I want to eat a mouse");
    Mieze.print_brain();
    Tiger = Mieze;
    Tiger.print_brain();
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
    animal_array();
    brain_test();
    return 0;
}