/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:57:35 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 13:48:04 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

class Contact {
	public:
		Contact();
		~Contact();
		void addInfo(void);
		void printInfo (void) const;
		std::string getfirstname(void) const;
		std::string getlastname(void) const;
		std::string getnickname(void) const;
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
		std::string _getString(std::string text);
};

#endif