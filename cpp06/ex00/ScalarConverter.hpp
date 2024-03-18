/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:59:29 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 09:19:17 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cctype>
class ScalarConverter{
    private:
        const std::string _input;
        enum Type{CHAR, INT, FLOAT, DOUBLE, PSEUDO_FLOAT, PSEUDO_DOUBLE, UNKNOWN};
        bool _hasDecimal;
        bool _hasSign;
        bool _hasF;
        size_t _start;
        ScalarConverter();
        ScalarConverter(const std::string &input);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &old_obj);
        ScalarConverter& operator=(const ScalarConverter &old_obj);
        void isChar(void);
        void isInt(void);
        void isFloat(void);
        void isDouble(void);
        Type determineLiteralType(const std::string &input);
    public:
        static void convert(const std::string &input);
};
#endif
