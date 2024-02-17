/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/17 11:55:41 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    {
    Bureaucrat a("Max", 10);
    Bureaucrat b("Danny",20);
    Form f("NBA Contract", 12,13);
    Form g(f);
    
    a.signForm(f);
    a.signForm(f);
    b.signForm(g);
    }
    try{
        std::cout << "Test1:\nGenerate Form with grade out of range\n";
        Form a("Anthony",0, 10);
        std::cout << a;
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}
