/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:32:39 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/02 15:03:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	std::string	line;
	std::size_t	index;
	std::string		filename = argv[1];
	std::string		new_file = filename + ".replace";
	std::ifstream	in_file(filename);
	std::ofstream	out_file(new_file);
	std::string	str_find(argv[2]);
	std::string str_replace(argv[3]);
	if (argc != 4)
		return (1);
	if (!in_file.is_open())
	{
		std::cout << "Error: in_file couldn't be opened" << std::endl;
		return (1);
	}
	if (!out_file.is_open())
	{
		std::cout << "Error: replace_file couldn't be created" << std::endl;
		return (1);
	}
	while ( std::getline(in_file,line))
	{
		index = line.find(argv[2]);
		// std::cout << index << std::endl;
		// std::cout << line << std::endl;
		out_file << line << std::endl;
	}
	return (0);
}