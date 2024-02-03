/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:56:45 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 18:38:53 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
class Bureaucrat;
class Form{
    private:
        const std::string    _name;
        bool    _sign;
        const int _sign_grade;
        const int _exec_grade;
    public:
        Form();
        Form(const std::string name, const int sign_grade, const int exec_grade);
        ~Form();
        Form(const Form &old_obj);
        Form& operator=(const Form &old_obj);

        int getSignGrade(void) const;
        int getExecGrade(void) const;
        const std::string getName(void) const;
        bool getSign(void) const;
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException: public std::exception{
            const char* what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
            const char* what(void) const throw();
        };
};
std::ostream & operator << (std::ostream &out, const Form &c);
#endif