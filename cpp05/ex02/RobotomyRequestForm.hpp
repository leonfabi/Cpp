/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:39:44 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/17 11:20:15 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm: public AForm{
    public:
        RobotomyRequestForm(const std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &old_obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &old_obj);

        void execute(Bureaucrat const &executor) const;
};

#endif