/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:21:19 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 10:32:21 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void){
	Harl	h;

	h.complain("debug");
	h.complain("info");
	h.complain("warning");
	h.complain("error");
	return (0);
}