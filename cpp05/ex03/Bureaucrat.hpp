/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:48:07 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 16:25:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"
class Bureaucrat{
    private:
        const std::string    _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &old_obj);
        Bureaucrat& operator=(const Bureaucrat &old_obj);

        const std::string& getName(void) const;
        int getGrade(void) const;
        void increment(void);
        void decrement(void);
        void signForm(AForm& f) const;
        void executeForm(AForm const & form);

        class GradeTooHighException: public std::exception{
            const char* what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
            const char* what(void) const throw();
        };
};
std::ostream & operator << (std::ostream &out, const Bureaucrat &c);
#endif
