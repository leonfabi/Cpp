/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 18:04:36 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
    {
    std::cout << "\n\n\n\033[3m\033[34m TEST1 ################\033[0m\n\n\n";
    Bureaucrat a("Max", 100);
    Bureaucrat b("Danny",4);
    PresidentialPardonForm president("Galaxy");

    a.signForm(president);
    b.signForm(president);
    a.executeForm(president);
    b.executeForm(president);
    }
    {
    std::cout << "\n\n\n\033[3m\033[34m TEST2 ################\033[0m\n\n\n";
    Bureaucrat a("Max", 138);
    Bureaucrat b("Danny",4);
    ShrubberyCreationForm tree("Cherry");

    b.signForm(tree);
    a.executeForm(tree);
    b.executeForm(tree);
    }
    {
    std::cout << "\n\n\n\033[3m\033[34m TEST3 ################\033[0m\n\n\n";
    Bureaucrat a("Max", 100);
    Bureaucrat b("Danny",4);
    RobotomyRequestForm robot("Angela");

    b.signForm(robot);
    a.executeForm(robot);
    b.executeForm(robot);
    }

    return (0);
}