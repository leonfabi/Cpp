/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:24:38 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 14:31:19 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iomanip>
#include <sstream>
class PhoneBook
{
	private:
		Contact _entries[8];
		static int _nbrentries;
		void _printColumn(std::string str)const;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(void);
		void searchPhonebook(void)const;
};

#endif
