/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:00:04 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 13:12:05 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void square(int& a){
    a *= a;
}

template <typename T> void print_typename(T& a){
    std::cout << "Payload: " << a << std::endl;
}

int main(void){
    int array[4] = {-1,-2,-4,-8};
    std::string string_array[3] = {"eins", "zwei", "drei"};
    ::iter(array, 4, print_typename<int>);
    ::iter(array, 4, square);
    ::iter(array, 4, print_typename<int>);
    ::iter(string_array, 3, print_typename<std::string>);
    return 0;
}
