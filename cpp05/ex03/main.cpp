/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/19 14:50:48 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
    {
    {
    std::cout << "\033[3m\033[34m TEST1: Form doesn't exist ################\033[0m\n\n\n";
    Bureaucrat a("Max", 100);
    Bureaucrat b("Danny",4);
    Intern I;
    try{
    AForm *form = I.makeForm("presidential pardons", "galaxy");
    a.signForm(*form);
    b.signForm(*form);
    a.executeForm(*form);
    b.executeForm(*form);
    }catch(std::exception& e){
        std::cout << e.what();
    }
    }
    {
    std::cout << "\033[3m\033[34m TEST2:wrong name ################\033[0m\n\n\n";
    Bureaucrat a("Max", 14);
    Intern I;
    try{
    AForm *president = I.makeForm("presidential pardon", "Mars");
    AForm *shrubbery = I.makeForm("shrubbery creation", "Venus");
    AForm *robotomy = I.makeForm("robotomy request", "Saturn");
    a.signForm(*president);
    a.executeForm(*president);
    a.signForm(*shrubbery);
    a.executeForm(*shrubbery);
    a.signForm(*robotomy);
    a.executeForm(*robotomy);
    }catch(std::exception& e){
        std::cout << e.what();
    }
    }
    }

    return (0);
}