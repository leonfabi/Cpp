/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:21:11 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/25 16:01:39 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);
  Contact getContactAt(int index) const;
  void setContact(Contact newContact);
  void printAllContacts() const;

 private:
  Contact contacts_[8];
  int contact_count_;
};

#endif
