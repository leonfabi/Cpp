/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:06 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 10:42:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
AForm("PresidentialPardonForm", 25, 5, target){
    std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &old_obj){
    if (this != &old_obj){
        AForm::operator=(old_obj);
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old_obj): AForm(old_obj){}