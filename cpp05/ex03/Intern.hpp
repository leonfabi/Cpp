/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:24:33 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/19 14:44:45 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private:
        static const std::string   options[3];
        typedef AForm* (Intern::*AFormFactory)(const std::string&);
        AForm* create_shrubbery_creation(const std::string& target);
        AForm* create_robotomy_request(const std::string& target);
        AForm* create_presidential_pardon(const std::string& target);
        static const AFormFactory factory[3];
    public:
        Intern();
        ~Intern();
        Intern(const Intern& old_obj);
        Intern& operator=(const Intern& old_obj);
        AForm* makeForm(const std::string name,const std::string target);
        class WrongForm: public std::exception{
            const char* what(void) const throw();
        };
};
#endif