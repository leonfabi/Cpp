/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:39:10 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 10:41:08 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
AForm("RobotomyRequestForm", 72, 45, target){
    std::cout << "RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &old_obj){
    if (this != &old_obj){
        AForm::operator=(old_obj);
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old_obj): AForm(old_obj){}