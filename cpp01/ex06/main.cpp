/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:21:19 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/03 14:42:56 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]){
	Harl	h;

	if (argc == 1){
		std::cerr << "Expected an argument\n";
		return (1);
	}
	h.complain(argv[1]);
	return (0);
}