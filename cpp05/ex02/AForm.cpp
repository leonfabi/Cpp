/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:20:49 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 18:41:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _sign(0), _sign_grade(1), _exec_grade(1), _target("Nothing") {
    std::cout << "AForm default constructor called\n";
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade, const std::string target):
 _name(name), _sign(0), _sign_grade(sign_grade), _exec_grade(exec_grade), _target(target) {
    std::cout << "AForm constructor called\n";
    if (_sign_grade < 1 || _exec_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _exec_grade > 150)
        throw GradeTooLowException();
}

AForm::~AForm(){
    std::cout << "AForm destructor called\n";
}

AForm::AForm(const AForm &old_obj):
_name(old_obj.getName()), _sign_grade(old_obj.getSignGrade()), _exec_grade(old_obj.getExecGrade()), _target(old_obj.getTarget()){
    *this = old_obj;
}

AForm& AForm::operator=(const AForm &old_obj){
    if (this!=&old_obj)
        _sign = old_obj._sign;
    return *this;
}

int AForm::getSignGrade(void) const{
    return _sign_grade;
}
int AForm::getExecGrade(void) const{
    return _exec_grade;
}
const std::string AForm::getName(void) const{
    return _name;
}

const std::string AForm::getTarget(void) const{
    return _target;
}

bool AForm::getSign(void) const{
    return _sign;
}

std::ostream & operator << (std::ostream &out, const AForm &c){
    out << c.getName() << ", AForm signed: " << c.getSign() << std::endl
    << "AForm sign grade: " << c.getSignGrade() << std::endl
    << "AForm exec grade: " << c.getExecGrade() << std::endl
    << "AForm target: " << c.getTarget() << std::endl;
    return out;
}

const char* AForm::GradeTooHighException::what(void) const throw(){
    return "Grade is too high\n";
}

const char* AForm::GradeTooLowException::what(void) const throw(){
    return "Grade is too low\n";
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= this->getSignGrade())
        _sign = true;
    else
        throw GradeTooLowException();
}