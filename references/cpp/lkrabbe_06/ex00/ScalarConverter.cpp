
#include	<string>
#include	<cmath>
#include	<iostream>
#include	<iomanip>
#include	<limits.h>
#include	<float.h>
#include	"ScalarConverter.hpp"
#include	<cerrno>

void	print_huge(std::string str)
{
	std::cout << "char: "<<   "impossible" << std::endl;
	std::cout << "int: "<<    "impossible" << std::endl;
	std::cout << "float: " <<  str << 'f' <<std::endl;
	std::cout << "double: "<< str << std::endl;
	return ;
}

void	print_result(char& type, double& value)
{
	switch(type)
	{
		case('e'):
		{
			std::cout << "invalid Input" << std::endl; 
			break;
		}
		case('+'):
		{
			print_huge("inf");
			break;
		}
		case('-'):
		{
			print_huge("-inf");
			break;
		}
		case('n'):
		{
			print_huge("nan");
			break;

		}
		case('r'):
		{
			std::cout << "Value is outside double range" << std::endl;
			break;
		}
		default:
		{


			if ( value > CHAR_MAX || value < CHAR_MIN)
				std::cout << "char: type converssion not possible "<< std::endl;
			else if (isprint(value) == true )
				std::cout << "char: '"<< static_cast<char>(value) << "'" << std::endl;
			else
				std::cout << "char: "<< "Non displayable" << std::endl;
			if (value > INT_MAX || value < INT_MIN)
				std::cout << "int: type converssion not possible " << std::endl;
			else
				std::cout << "int: "<< static_cast<int>(value) << std::endl;
			if (type == 'd')
				std::cout << "float: type converssion not possible " << std::endl;
			else
				std::cout << "float: "  << std::setprecision(1) << std::fixed << static_cast<float>(value) << "f"<< std::endl;
			std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(value) << std::endl;
		}
	}
}

void	check_type(const std::string arg, char& type, double& value)
{
	if (arg.size() == 0)
		return;
	{
		char *endptr = NULL;
		value = strtod(arg.c_str(),&endptr);
	}
	if (arg.size() == 1)
	{
		if (isdigit((char)arg[0]) == false)
		{
			type = 'c';
			value = arg[0];
		}
		else
		{
			type = 'i';
			value = arg[0] - '0';
		}
		return;
	}
	{
		if (arg.compare("nan") == 0 || arg.compare("nanf")  == 0 || isnan(value))
			type = 'n';
		else if (arg.compare("+inf") == 0  || arg.compare("+inff") == 0  ||arg.compare("inf") == 0  || arg.compare("inff") == 0 )
			type = '+';
		else if  (arg.compare("-inf") == 0 || arg.compare("-inff") == 0 )
			type = '-';
	}
	if (type != '0')
	{
		return;
	}
	{
		char *endptr = NULL;
		strtol(arg.c_str(),&endptr,10);
		if (*endptr == '\0' && errno != ERANGE)
		{
			type = 'i';
			value = strtod(arg.c_str(),&endptr);
			// std::cout << "here" << std::endl;
			return;
		}
	}
	{
		char *endptr = NULL;
		float f = strtof(arg.c_str(),&endptr);
		if (f != HUGE_VALF && ((*endptr == 'f' && endptr[1] == '\0') || *endptr == '\0') && errno != ERANGE)
		{
			type = 'f';
			value = f;
			return;
		}
	}
	{
		char *endptr = NULL;
		double d = strtod(arg.c_str(),&endptr);
		if(errno == ERANGE)
		{
			type = 'r';
		}
		else if (*endptr == '\0')
		{
			type = 'd';
			value = d;
			if (d == HUGE_VAL)
				type = '+';
			return;
		}
		else
			type = 'e';
	}
}

void	ScalarConverter::convert(std::string arg)
{
	char type = '0';
	double value = 0;
	check_type(arg, type, value);
	print_result(type, value);
}


















































ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{
	(void)a;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& a)
{
	(void)a;
	return (*(this));
}
