/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:24:33 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 18:11:23 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& old_obj);
        Intern& operator=(const Intern& old_obj);

        AForm* makeForm(const std::string name,const std::string target);
        static const std::string   options[3];
        class WrongForm: public std::exception{
            const char* what(void) const throw();
        };
};
#endif