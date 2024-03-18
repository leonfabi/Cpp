/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeInfo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:42:35 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 12:03:02 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeInfo.hpp"

Base* generate(void){
    std::srand(time(NULL));
    size_t r_value = std::rand() % 3;
    switch (r_value)
    {
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        default:
            return new C();
            break;
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "Identified as class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified as class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified as class C" << std::endl;
    else
        std::cout << "Unknown class" << std::endl;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified as class A" << std::endl;
    } catch (const std::exception &){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified as class B" << std::endl;
    } catch (const std::exception &){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified as class C" << std::endl;
    } catch (const std::exception &){}
}