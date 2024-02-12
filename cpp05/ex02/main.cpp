/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 15:44:25 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
    {
    Bureaucrat a("Max", 100);
    Bureaucrat b("Danny",4);
    PresidentialPardonForm f("Galaxy");
    
    a.signForm(f);
    b.signForm(f);
    }
    return (0);
}