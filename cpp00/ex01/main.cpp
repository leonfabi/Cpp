#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string tmp;
	std::cout << "Phonebook" << std::endl;
	while (true)
	{
		std::cout << "<Command>: ";
		std::getline(std::cin, tmp);
		if (!tmp.compare("ADD"))
			book.addContact();
		else if (!tmp.compare("SEARCH"))
			book.searchPhonebook();
		else if (!tmp.compare("EXIT"))
			break;
	}
	return (0);
}