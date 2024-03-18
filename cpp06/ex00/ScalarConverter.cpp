/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:20:21 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 09:36:48 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string &input) :
_input(input), _hasDecimal(false), _hasSign(false), _hasF(false), _start(0){
}

ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::~ScalarConverter(){
    // std::cout << "ScalarConverter destructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &old_obj){
    *this = old_obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &old_obj){
    (void)old_obj;
    return *this;
}

ScalarConverter::Type ScalarConverter::determineLiteralType(const std::string &input){
    if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf" || input == "+nanf" || input == "-nanf")
        return PSEUDO_FLOAT;
    else if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan" || input == "+nan" || input == "-nan")
        return PSEUDO_DOUBLE;
    else if (input.length() == 1 && !std::isdigit(input[0])){
        return CHAR;
    }
    _hasDecimal = false;
    _hasSign = (input[0] == '+' || input[0] == '-');
    _hasF = false;
    _start = _hasSign ? 1 : 0;
    for (size_t i = _start; i < input.length(); i++){
        if (input[i] == '.'){
            if (_hasDecimal || i == input.length() - 1 || i == _start)
                return UNKNOWN;
            _hasDecimal = true;
        }
        else if (input[i] == 'f' || input[i] == 'F'){
            if (_hasF || !_hasDecimal || i == input.find('.') + 1 || i != input.length() - 1)
                return UNKNOWN;
            _hasF = true;
        }
        else if (!std::isdigit(input[i])){
            return UNKNOWN;
        }
    }
    if (_hasDecimal)
        return _hasF ? FLOAT : DOUBLE;
    else
        return INT;
    }

void ScalarConverter::convert(const std::string &input){
    
    ScalarConverter sc(input);
    int tmp;
    tmp = sc.determineLiteralType(input);
    switch (tmp)
    {
    case INT:
        std::cout << "INT\n";
        sc.isInt();
        break;
    case FLOAT:
        std::cout << "FLOAT\n";
        sc.isFloat();
        break;
    case CHAR:
        std::cout << "CHAR\n";
        sc.isChar();
        break;
    case DOUBLE:
        std::cout << "DOUBLE\n";
        sc.isDouble();
        break;
    case PSEUDO_DOUBLE:
        std::cout << "PSEUDO_DOUBLE\n";
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: "<< input << "f\n"
        << "double: " << input << "\n";
        break;
    case PSEUDO_FLOAT:
        std::cout << "PSEUDO_FLOAT\n";
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: "<< input << "\n"
        << "double: " << input.substr(0, input.length() - 1) << "\n";
        break;
    default:
        std::cout << "UNKNOWN\n";
        break;
    }
}

void ScalarConverter::isChar(void){
    char c = _input[0];
    std::cout << "char: " << c << "\n"
    << "int: " << static_cast<int>(c) << "\n" << std::setprecision(1) << std::fixed
    << "float: " << static_cast<float>(c) << "f\n"
    << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::isInt(void){
    std::istringstream stream(_input);
    long double i;
    stream >> i;
    std::cout << std::setprecision(10);
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min()){
        std::cout << "\"" << _input << "\" Not convertable because of Integer overflow\n";
        return ;
    }
    if (i > 255 || i < 0 || !std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(i) << "\n";
    std::cout << "int: " << i << "\n";
    std::cout << std::setprecision(1) << std::fixed;
    if (i > std::numeric_limits<float>::max() || i < -std::numeric_limits<float>::max())
        std::cout << "float: overflow\n";
    else
        std::cout << "float: " << static_cast<float>(i) << "f\n";
    if (i > std::numeric_limits<double>::max() || i < -std::numeric_limits<double>::max())
        std::cout << "double: overflow\n";
    else
        std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::isFloat(void){
    std::string stringFloat = _input.substr(0, _input.length() - 1);
    std::istringstream stream(stringFloat);
    long double i;
    size_t commaPosition = stringFloat.find('.');
    int precision = commaPosition != std::string::npos ? stringFloat.length() - commaPosition - 1 : 0;
    stream >> i;
    if (i > std::numeric_limits<float>::max() || i < -std::numeric_limits<float>::max()){
        std::cout << "\"" << _input << "\" Not convertable because of Float overflow\n";
        return ;
    }
    if (i > 255 || i < 0 || !std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(i) << "\n";
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
        std::cout << "int: overflow\n";
    else
        std::cout << "int: " << static_cast<int>(i) << "\n";
    std::cout << std::setprecision(precision) << std::fixed;
    std::cout << "float: " << i << "f\n";
    if (i > std::numeric_limits<double>::max() || i < -std::numeric_limits<double>::max())
        std::cout << "double: overflow\n";
    else
        std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::isDouble(void){
    std::istringstream stream(_input);
    long double i;
    size_t commaPosition = _input.find('.');
    int precision = commaPosition != std::string::npos ? _input.length() - commaPosition - 1 : 0;
    stream >> i;
    if (i > std::numeric_limits<double>::max() || i < -std::numeric_limits<double>::max()){
        std::cout << "\"" << _input << "\" Not convertable because of Double overflow\n";
        return ;
    }
    if (i > 255 || i < 0 || !std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(i) << "\n";
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
        std::cout << "int: overflow\n";
    else
        std::cout << "int: " << static_cast<int>(i) << "\n";
    std::cout << std::setprecision(precision) << std::fixed;
    if (i > std::numeric_limits<float>::max() || i < -std::numeric_limits<float>::max())
        std::cout << "float: overflow\n";
    else
        std::cout << "float: " << static_cast<float>(i) << "f\n";
    std::cout << "double: " << i << "\n";
}