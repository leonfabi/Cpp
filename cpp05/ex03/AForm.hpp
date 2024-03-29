/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:56:45 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 18:38:53 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
class Bureaucrat;
class AForm{
    private:
        const std::string    _name;
        bool    _sign;
        const int _sign_grade;
        const int _exec_grade;
        const std::string   _target;
    public:
        AForm();
        AForm(const std::string name, const int sign_grade, const int exec_grade, const std::string target);
        virtual ~AForm();
        AForm(const AForm &old_obj);
        AForm& operator=(const AForm &old_obj);

        int getSignGrade(void) const;
        int getExecGrade(void) const;
        const std::string getName(void) const;
        const std::string getTarget(void) const;
        bool getSign(void) const;
        bool isExecutable(Bureaucrat const & executor) const;
        virtual void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException: public std::exception{
            const char* what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
            const char* what(void) const throw();
        };
        class FormNotSignedException: public std::exception{
            const char* what(void) const throw();
        };

        class ExecutionNotAllowed: public std::exception{
            const char* what(void) const throw();
        };
};
std::ostream & operator << (std::ostream &out, const AForm &c);
#endif