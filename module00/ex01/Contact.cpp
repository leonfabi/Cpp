/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:11:36 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/17 14:17:33 by fkrug            ###   ########.fr       */
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

Contact::Contact(Contact &old)
{
	
}