/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:36:40 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/03 17:50:55 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
    try{
        std::cout << "Test1:\nGenerate Bureaucrat with grade out of range\n";
        Bureaucrat a("Anthony",151);
        std::cout << a;
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "Test2:\nDecrement grade out of range\n";
        Bureaucrat b("Luka",149);
        std::cout << b;
        b.decrement();
        std::cout << b;
        b.decrement();
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "Test3:\nIncrement grade out of range\n";
        Bureaucrat c("Nikola",2);
        std::cout << c;
        c.increment();
        std::cout << c;
        c.increment();
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "Test4:\nCopy constructor\n";
        Bureaucrat d("LeBron",2);
        Bureaucrat e(d);
        d.increment();
        std::cout << d;
        std::cout << e;
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}