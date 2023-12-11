#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "New PhoneBook generated" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook got deleted" << std::endl;
}

void PhoneBook::addContact(void)
{
	if (_nbrentries == 8)
		_nbrentries = 0;
	_entries[_nbrentries].addInfo();
	_nbrentries++;
}

void PhoneBook::_printColumn(std::string str)const
{
	std::cout << std::right << std::setw(10) << ((str.length() > 10) ? str.substr(0,9) + '.' : str) << '|';
}

void PhoneBook::searchPhonebook(void)const
{
	std::string tmp;
	std::stringstream s;
	std::cout << "PHONEBOOK" << std::endl;
	std::cout << '|';
	_printColumn("index");
	_printColumn("first name");
	_printColumn("last name");
	_printColumn("nick name");
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		s.str("");
		s << i;
		std::cout << '|';
		_printColumn(s.str());
		_printColumn(_entries[i].getfirstname());
		_printColumn(_entries[i].getlastname());
		_printColumn(_entries[i].getnickname());
		std::cout << std::endl;
	}
	std::cout << "Index of the entry: ";
	std::getline(std::cin, tmp);
	if (tmp.length() == 1 && tmp[0] >= '0' && tmp[0] <= '7')
	{
		_entries[tmp[0] - '0'].printInfo();
	}
	else
	{
		std::cout << "Error: number out of range" << std::endl;
		return ;
	}
}

int PhoneBook::_nbrentries = 0;