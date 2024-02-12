/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:33 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 18:12:49 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::options[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern(){
    std::cout << "Intern constructor called\n";
}

Intern::~Intern(){}

Intern& Intern::operator=(const Intern& old_obj){
    (void)old_obj;
    return *this;
}

Intern::Intern(const Intern& old_obj){
    *this = old_obj;
}

const char* Intern::WrongForm::what(void) const throw(){
    return "Intern didn't know what he was doing\n";
}


AForm* Intern::makeForm(const std::string name, const std::string target){
    int index = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if (!name.compare(Intern::options[i]))
            index = i;
    }
    switch (index)
    {
    case 0:
        std::cout << "Intern creates form " << name << ".\n";
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates form " << name << ".\n";
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates form " << name << ".\n";
        return new PresidentialPardonForm(target);
    default:
        throw WrongForm();
        return NULL;
    }
}
