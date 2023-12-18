/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:26:10 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/17 14:06:19 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
  this->contact_count_ = 0;
  //std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
  //std::cout << "PhoneBook destructor called" << std::endl;
}

Contact PhoneBook::getContactAt(int index) const {
  return this->contacts_[index];
}

void PhoneBook::setContact(Contact newContact) {
  if (this->contact_count_ == 8) {
    this->contact_count_ = 0;
  }
  this->contacts_[contact_count_] = newContact;
  this->contact_count_++;
}

void PhoneBook::printAllContacts(void) const {
  std::cout << " ___________________________________________ " << std::endl;
  std::cout << "|ID        |First Name|Last Name |Nickname  |" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::cout << "|         " << i;
    this->contacts_[i].printContact();
  }
  std::cout << "|__________|__________|__________|__________|" << std::endl;
}
