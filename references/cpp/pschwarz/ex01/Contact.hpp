/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:47:58 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/25 16:05:59 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <string>

class Contact {
 public:
  Contact();
  Contact(
    std::string first_name,
    std::string last_name,
    std::string nick_name,
    std::string phone_number,
    std::string darkest_secret
  );
  ~Contact(void);
  std::string getFirstName(void) const;
  std::string getFullName(void) const;
  void printContact(void) const;
  void printContactVerbose(void) const;

 private:
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;
};

#endif
