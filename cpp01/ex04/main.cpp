/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:32:39 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 10:15:03 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4){
		std::cerr << "ERROR Expected: ./replace <filename> <find> <replace>" << std::endl;
		return (EXIT_FAILURE);
	}
	if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty()){
		std::cerr << "ERROR: Strings can't be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	line, filename = argv[1], str_find(argv[2]), str_replace(argv[3]);
	std::string::size_type	l(str_find.length());
	std::size_t	index;
	std::ifstream	in_file(filename);
	std::ofstream	out_file;//(filename + ".replace");
	if (!in_file.is_open())
	{
		std::cerr << "Error: input file couldn't be opened" << std::endl;
		return (EXIT_FAILURE);
	}
	out_file.open(filename + ".replace");
	if (!out_file.is_open())
	{
		std::cerr << "Error: output file couldn't be opened" << std::endl;
		return (EXIT_FAILURE);
	}
	while (std::getline(in_file,line))
	{
		index = 0;
		while ((index = line.find(str_find, index)) != std::string::npos){
			if ((index != 0 && line[index - 1] != ' ') || 
			(index + l < line.length() && line[index + l] != ' ')){
				index += l;
				continue;
			}
			line.erase(index, l);
			line.insert(index, str_replace);
			index += l;
		}
		out_file << line << std::endl;
	}
	out_file.close();
	in_file.close();
	return (0);
}