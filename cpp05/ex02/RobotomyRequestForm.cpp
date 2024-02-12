/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:39:10 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 16:48:51 by fkrug            ###   ########.fr       */
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (this->isExecutable(executor) == true){
        std::srand(std::time(0));
        std::cout << "\033[3m\033[34m" << "Vrrrrrrrrrmmmmmmmmmm.... Vrrrmmmm... VRRRRRRRRRR!!!\n";
        if (std::rand() % 2)
            std::cout << this->getTarget() << " has been robotomized successfully!!!\033[0m\n";
        else
            std::cout << "Oh nooooooo the robotomy for " << this->getTarget() << " failed:(\033[0m\n";
    }
}