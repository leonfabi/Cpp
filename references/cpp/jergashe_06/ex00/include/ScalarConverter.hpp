#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

class ScalarConverter {
   private:
	// parsing
	static void parseInput(std::string &input);
	static bool isWrongInput(std::string &input);
	static bool isValidNumber(std::string &input);
	static bool isPseudo(std::string &input);

	// conversion
	static double stringToDouble(std::string &str);

	// print
	static bool isPrintableASCII(int i);
	static void printChar(double &value, std::string &input);
	static void printInt(double &value, std::string &input);
	static void printDouble(double &value, std::string &input);
	static void printFloat(double &value, std::string &input);

   public:
	static void convert(std::string &input);

	class WrongInputException : public std::exception {
	   public:
		virtual const char *what() const throw();
	};
};

#endif