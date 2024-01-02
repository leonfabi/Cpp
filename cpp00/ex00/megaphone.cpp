/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:07:48 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 10:57:34 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char* argv[])
{
	int	count = 0;
	std::string str;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++count < argc)
		{
			str = argv[count];
			for (std::string::size_type i = 0; i < str.length(); i++)
				str[i] = std::toupper(str[i]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}