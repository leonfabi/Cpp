/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:54:30 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 16:32:50 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1){
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade){
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj): _name(old_obj.getName()){
    *this = old_obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &old_obj){
    if (this!=&old_obj)
        _grade = old_obj._grade;
    return *this;
}

const std::string& Bureaucrat::getName(void) const{
    return _name;
}

int Bureaucrat::getGrade(void) const{
    return _grade;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &c){
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".\n";
    return out;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
    return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
    return "Grade is too low\n";
}

void Bureaucrat::increment(void){
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrement(void){
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

 void Bureaucrat::signForm(AForm& f) const{
    if (f.getSign() == true){
        std::cout << "Form is already signed\n";
        return;
    }
    try{
        f.beSigned(*this);
        std::cout << this->getName() << " signed Form: " << f.getName() << std::endl;
    }catch(std::exception &e){
        std::cout << this->getName() << " couldn't sign the Form: " << f.getName()
        << " because " << e.what();
    }
 }

void Bureaucrat::executeForm(AForm const & form){
    try{
        form.execute(*this);
        std::cout << "\033[1m\033[32m" << this->getName() << " executed " << form.getName() << ".\033[0m\n";
    }catch (std::exception& e){
        std::cout << "\033[1m\033[31m" << this->getName() << " wasn't able to execute the form " << form.getName() << ".\033[0m\n";
    }
 }