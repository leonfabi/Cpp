/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:33 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/19 14:44:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::options[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

const Intern::AFormFactory Intern::factory[3] = {
    &Intern::create_shrubbery_creation,
    &Intern::create_robotomy_request,
    &Intern::create_presidential_pardon
};

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
    return "Intern didn't know what he was doing\nThe options are ['shrubbery creation', 'robotomy request', 'presidential pardon']";
}


AForm* Intern::makeForm(const std::string name, const std::string target){
    for (size_t i = 0; i < 3; i++)
    {
        if (name == options[i])
            return (this->*factory[i])(target);
    }
    throw WrongForm();
}

AForm* Intern::create_shrubbery_creation(const std::string& target){
    return new ShrubberyCreationForm(target);
}
AForm* Intern::create_robotomy_request(const std::string& target){
    return new RobotomyRequestForm(target);
}
AForm* Intern::create_presidential_pardon(const std::string& target){
    return new PresidentialPardonForm(target);
}