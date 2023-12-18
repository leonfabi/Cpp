/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:25:42 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/25 16:27:40 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool getInputValues(Contact &newContact);
void printWelcome(void);

int main(void) {
  PhoneBook myPhoneBook;
  std::string input;
  int index;
  Contact newContact;

  printWelcome();
  while (std::cin) {
    std::cout << "Input (ADD | SEARCH | EXIT): ";
    std::getline(std::cin, input);
    if (input == "EXIT")
      break;
    else if (input == "ADD") {
      if (getInputValues(newContact)) {
        myPhoneBook.setContact(newContact);
      }
    } else if (input == "SEARCH") {
      myPhoneBook.printAllContacts();
      std::cout << "Input index: ";
      getline(std::cin, input);
      std::stringstream(input) >> index;
      if (!std::cin || !input.length() || !isdigit(input.at(0)) ||
          input.length() > 1)
        std::cerr << "ERROR: no invalid index pls" << std::endl;
      else {
        if (index >= 0 && index < 8)
          myPhoneBook.getContactAt(index).printContactVerbose();
        else
          std::cerr << "ERROR: no invalid index pls" << std::endl;
      }
    }
  }
  return (0);
}

bool getInputValues(Contact &newContact) {
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  std::cout << "Input first name: ";
  std::getline(std::cin, first_name);
  std::cout << "Input last name: ";
  std::getline(std::cin, last_name);
  std::cout << "Input nick name: ";
  std::getline(std::cin, nick_name);
  std::cout << "Input phone number: ";
  std::getline(std::cin, phone_number);
  std::cout << "Input your darkest secret: ";
  std::getline(std::cin, darkest_secret);
  if (first_name.length() && last_name.length() && nick_name.length() &&
      phone_number.length() && darkest_secret.length()) {
    newContact =
        Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
    return true;
  }
  std::cerr << "ERROR: no empty fields pls" << std::endl;
  return false;
}

void printWelcome(void) {
  std::cout << " ___________________________________________ " << std::endl;
  std::cout << "|                                           |" << std::endl;
  std::cout << "| Welcome to the wonderful PhoneBook        |" << std::endl;
  std::cout << "|___________________________________________|" << std::endl;
  std::cout << "|                                           |" << std::endl;
  std::cout << "| use ADD to add a new contact              |" << std::endl;
  std::cout << "|                                           |" << std::endl;
  std::cout << "| use SEARCH to find a contact              |" << std::endl;
  std::cout << "|                                           |" << std::endl;
  std::cout << "| use EXIT to quit and lose all data        |" << std::endl;
  std::cout << "|___________________________________________|" << std::endl;
}
