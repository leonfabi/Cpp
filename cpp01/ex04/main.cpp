/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:32:39 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/05 10:26:36 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

static void replace(std::string& line, std::string& str_find, std::string& str_replace, std::string::size_type length)
{
	std::size_t	index = 0;
	while ((index = line.find(str_find, index)) != std::string::npos){
		if ((index != 0 && line[index - 1] != ' ') || 
		(index + length < line.length() && line[index + length] != ' ')){
			index += length;
			continue;
		}
		line.erase(index, length);
		line.insert(index, str_replace);
		index += length;
	}
}

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
	std::ifstream	in_file(filename);
	std::ofstream	out_file;
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
		replace(line, str_find, str_replace, l);
		out_file << line << std::endl;
	}
	out_file.close();
	in_file.close();
	return (0);
}