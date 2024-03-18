/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:18:24 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 14:43:58 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Usage: ./convert [literal]\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}