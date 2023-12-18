/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:48:10 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/17 13:19:43 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

std::string tableTrim(std::string str);

Contact::Contact() {
  //std::cout << "Contact constructor called" << std::endl;
}

Contact::Contact(std::string first_name, std::string last_name,
    std::string nick_name, std::string phone_number, std::string darkest_secret)
    : first_name(first_name),
      last_name(last_name),
      nick_name(nick_name),
      phone_number(phone_number),
      darkest_secret(darkest_secret) {
  //std::cout << "contact constructor called" << std::endl;
}

Contact::~Contact(void) {
  //std::cout << "contact destructor called" << std::endl;
}

std::string Contact::getFirstName(void) const {
  return this->first_name;
}

std::string Contact::getFullName(void) const {
  return this->first_name + " " + this->last_name;
}

void Contact::printContact(void) const {
  std::cout << "|";
  std::cout << std::setw(10) << tableTrim(this->first_name) << "|";
  std::cout << std::setw(10) << tableTrim(this->last_name) << "|";
  std::cout << std::setw(10) << tableTrim(this->nick_name) << "|" << std::endl;
}

void Contact::printContactVerbose(void) const {
  std::cout << "first name: " << this->first_name << std::endl;
  std::cout << "last name: " << this->last_name << std::endl;
  std::cout << "nick name: " << this->nick_name << std::endl;
  std::cout << "phone number: " << this->phone_number << std::endl;
  std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}

std::string tableTrim(std::string str) {
  if (str.length() > 10) {
    return str.substr(0, 9).replace(9, 1, ".");
  }
  return str;
}
