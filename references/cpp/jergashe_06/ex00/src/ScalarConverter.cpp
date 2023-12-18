#include "../include/ScalarConverter.hpp"

// ************************************************************************** //
//                               PUBLIC                                       //
// ************************************************************************** //

void ScalarConverter::convert(std::string& input) {
	double value;
	if (isWrongInput(input)) throw(ScalarConverter::WrongInputException());
	value = stringToDouble(input);
	printChar(value, input);
	printInt(value, input);
	printFloat(value, input);
	printDouble(value, input);
}

// ************************************************************************** //
//                               PARSING                                      //
// ************************************************************************** //

void ScalarConverter::parseInput(std::string& input) {
	input = input.substr(
		input.find_first_not_of(' '),
		input.find_last_not_of(' ') - input.find_first_not_of(' ') + 1);  // trim of spaces
	if (isPseudo(input) == false &&
		input.at(input.size() - 1) == 'f')	// remove f for inff, nanf...
		input = input.substr(0, input.size() - 1);
}

bool ScalarConverter::isValidNumber(std::string& input) {
	unsigned int i = 0;
	int dotCount = 0;
	while ((input.at(i) == '+' || input.at(i) == '-') && i < input.size()) i++;
	while (i < input.size()) {
		if ((input.at(i) < '0' || input.at(i) > '9') && input.at(i) != '.') return false;
		if (input.at(i) == '.') dotCount++;
		i++;
	}
	if (dotCount > 1) return false;
	return true;
}

bool ScalarConverter::isWrongInput(std::string& input) {
	double value;

	if (input.size() == 0) return true;
	parseInput(input);
	if (input.find(' ') != std::string::npos) return true;
	if (isPseudo(input)) return false;
	if (isValidNumber(input) == false) return true;
	std::istringstream iss(input);
	if (iss >> value)
		return false;
	else
		throw(ScalarConverter::WrongInputException());
	return false;
}

bool ScalarConverter::isPseudo(std::string& input) {
	const char* pseudoliterals[4] = {"+inf", "inf", "-inf", "nan"};
	for (int i = 0; i < 4; ++i) {
		if (input.compare(pseudoliterals[i]) == 0) return true;
	}
	return false;
}

// ************************************************************************** //
//                               PRINTING                                     //
// ************************************************************************** //

bool ScalarConverter::isPrintableASCII(int i) { return (i >= 32 && i <= 126); }

void ScalarConverter::printDouble(double& value, std::string& input) {
	if ((value > std::numeric_limits<double>::max() ||
		 value < -std::numeric_limits<double>::max()) &&
		isPseudo(input) == false) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::printFloat(double& value, std::string& input) {
	float num = static_cast<float>(value);
	if ((value > static_cast<double>(std::numeric_limits<float>::max()) ||
		 value < -static_cast<double>(std::numeric_limits<float>::max())) &&
		isPseudo(input) == false) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	}
}

void ScalarConverter::printInt(double& value, std::string& input) {
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() ||
		isPseudo(input)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int num = static_cast<int>(value);
		std::cout << "int: " << num << std::endl;
	}
}

void ScalarConverter::printChar(double& value, std::string& input) {
	char ch = static_cast<char>(value);

	if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min() ||
		isPseudo(input)) {
		std::cout << "char: impossible" << std::endl;
	} else if (isPrintableASCII(ch)) {
		std::cout << "char: '" << ch << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

// ************************************************************************** //
//                               CONVERTION                                   //
// ************************************************************************** //

double ScalarConverter::stringToDouble(std::string& str) {
	double value;
	const char* pseudoliterals[4] = {"+inf", "inf", "-inf", "nan"};
	int index = 0;

	if (isPseudo(str)) {
		for (; index < 4; index++) {
			if (str.compare(pseudoliterals[index]) == 0) break;
		}
		switch (index) {
			case 0:
				return std::numeric_limits<double>::infinity();
			case 1:
				return std::numeric_limits<double>::infinity();
			case 2:
				return -std::numeric_limits<double>::infinity();
			case 3:
				return std::numeric_limits<double>::quiet_NaN();
		}
	}
	std::istringstream iss(str);
	if (iss >> value)
		return value;
	else
		throw(ScalarConverter::WrongInputException());
	return -1;
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* ScalarConverter::WrongInputException::what() const throw() { return "Wrong Input!\n"; }
