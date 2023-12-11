/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:11:36 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 14:30:40 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "New Contact created" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact is being deleted" << std::endl;
}

void	Contact::addInfo(void)
{
	_firstname = _getString("First Name: ");
	_lastname = _getString("Last Name: ");
	_nickname = _getString("Nickname: ");
	_phonenumber = _getString("Phonenumber: ");
	_darkestsecret = _getString("Darkest secret: ");
}

std::string	Contact::_getString(std::string text)
{
	std::string str;
	std::cout << text;
	std::getline(std::cin, str);
	return str;
}

void Contact::printInfo (void) const
{
	std::cout << "First Name: " << _firstname << std::endl;
	std::cout << "Last Name: " << _lastname << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phonenumber: " << _phonenumber << std::endl;
	std::cout << "Darkest secret: " << _darkestsecret << std::endl;
}

std::string Contact::getfirstname(void) const
{
	return _firstname;
}

std::string Contact::getlastname(void) const
{
	return _lastname;
}

std::string Contact::getnickname(void) const
{
	return _nickname;
}