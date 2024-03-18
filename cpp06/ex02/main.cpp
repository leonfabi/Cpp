/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:00:37 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 12:06:41 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeInfo.hpp"

int main() {
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    identify(a);
    identify(b);
    identify(c);

    identify(*a);
    identify(*b);
    identify(*c);

    delete a;
    delete b;
    delete c;

    std::cout << "Random generator: ";
    identify(generate());
    return 0;
}
