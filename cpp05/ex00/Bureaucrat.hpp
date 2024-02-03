/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:48:07 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 17:29:45 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
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

        class GradeTooHighException: public std::exception{
            const char* what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
            const char* what(void) const throw();
        };
};
std::ostream & operator << (std::ostream &out, const Bureaucrat &c);
#endif
