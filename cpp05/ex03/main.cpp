/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/19 13:27:54 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
    {
    {
    std::cout << "\033[3m\033[34m TEST1:Wrong name ################\033[0m\n\n\n";
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
    Bureaucrat a("Max", 100);
    Bureaucrat b("Danny",4);
    Intern I;
    try{
    AForm *form = I.makeForm("presidential pardon", "galaxy");
    a.signForm(*form);
    b.signForm(*form);
    a.executeForm(*form);
    b.executeForm(*form);
    }catch(std::exception& e){
        std::cout << e.what();
    }
    }
    }

    return (0);
}