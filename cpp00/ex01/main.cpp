/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:07:29 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 15:07:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string tmp;
	std::cout << "Phonebook" << std::endl;
	std::cout << "ADD: add contact | SEARCH: search for contact information | EXIT: exit the Phonebook" << std::endl;
	while (true)
	{
		std::cout << ">> ";
		std::getline(std::cin, tmp);
		if (!tmp.compare("ADD"))
			book.addContact();
		else if (!tmp.compare("SEARCH"))
			book.searchPhonebook();
		else if (!tmp.compare("EXIT"))
			break;
		else
			std::cout << "Unknown command" << std::endl
			<< "Available commands: ADD|SEARCH|EXIT" << std::endl;
	}
	return (0);
}