/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:18:24 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/04 17:09:07 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Usage: ./convert [literal]\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    // std::cout << "What happens if I try to cast an str to an Int? " << static_cast<int>(999999999999999)<< "\n";
    return 0;
}