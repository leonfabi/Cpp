/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:20:49 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 18:41:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _sign(0), _sign_grade(1), _exec_grade(1) {
    std::cout << "Form default constructor called\n";
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade):
 _name(name), _sign(0), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    std::cout << "Form constructor called\n";
    if (_sign_grade < 1 || _exec_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _exec_grade > 150)
        throw GradeTooLowException();
}

Form::~Form(){
    std::cout << "Form destructor called\n";
}

Form::Form(const Form &old_obj):
_name(old_obj.getName()), _sign_grade(old_obj.getSignGrade()), _exec_grade(old_obj.getExecGrade()){
    *this = old_obj;
}

Form& Form::operator=(const Form &old_obj){
    if (this!=&old_obj)
        _sign = old_obj._sign;
    return *this;
}

int Form::getSignGrade(void) const{
    return _sign_grade;
}
int Form::getExecGrade(void) const{
    return _exec_grade;
}
const std::string Form::getName(void) const{
    return _name;
}
bool Form::getSign(void) const{
    return _sign;
}

std::ostream & operator << (std::ostream &out, const Form &c){
    out << c.getName() << ", Form signed: " << c.getSign() << std::endl
    << "Form sign grade: " << c.getSignGrade() << std::endl
    << "Form exec grade: " << c.getExecGrade() << std::endl;
    return out;
}

const char* Form::GradeTooHighException::what(void) const throw(){
    return "Grade is too high\n";
}

const char* Form::GradeTooLowException::what(void) const throw(){
    return "Grade is too low\n";
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= this->getSignGrade())
        _sign = true;
    else
        throw GradeTooLowException();
}