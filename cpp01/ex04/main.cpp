/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:32:39 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/03 08:58:46 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	std::string	line;
	std::size_t	index;
	std::string		filename = argv[1];
	std::string		new_file = filename + ".replace";
	std::ifstream	in_file(filename);
	std::ofstream	out_file(new_file);
	std::string	str_find(argv[2]);
	std::string	str_replace(argv[3]);
	std::string::size_type	l(str_find.length());
	if (!in_file.is_open() || !out_file.is_open())
	{
		std::cout << "Error: file couldn't be opened" << std::endl;
		return (1);
	}

	while ( std::getline(in_file,line))
	{
		index = 0;
		while ((index = line.find(str_find, index)) != std::string::npos){
			if (index != 0 && line[index - 1] != ' '){
				index += l;
				continue;
			}
			if (index + l < line.length() && line[index + l] != ' '){
				index += l;
				continue;
			}
			std::cout << "String found at line[" << index << "]" << std::endl;
			index += l;
		}
		// std::cout << index << std::endl;
		// std::cout << line << std::endl;
		out_file << line << std::endl;
	}
	return (0);
}