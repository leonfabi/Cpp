#include "Fixed.hpp"

int main( void ) {
	Fixed a(3.5f);
	Fixed b(4.1f );
	Fixed const c(2.9f);
	Fixed const d(1.7f);

	std::cout << "smaller as:\t" << (a < b) << std::endl;
	std::cout << "bigger as:\t" << (a > b) << std::endl;
	std::cout << "smaller equal:\t" << (a <= b) << std::endl;
	std::cout << "bigger equal:\t" << (a >= b) << std::endl;
	std::cout << "equals:\t\t" << (a == b) << std::endl;
	std::cout << "unequal:\t" << (a != b) << std::endl;
	std::cout << "addition:\t" << (a + b) << std::endl;
	std::cout << "subtraction:\t" << (a - b) << std::endl;
	std::cout << "multiplication:\t" << (a * b) << std::endl;
	std::cout << "division:\t" << (a / Fixed(0)) << std::endl;
	std::cout << "increase post:\t" << a++ << std::endl;
	std::cout << "increase pre:\t" << ++a << std::endl;
	std::cout << "decrease post:\t" << a++ << std::endl;
	std::cout << "decrease pre:\t" << ++a << std::endl;
	std::cout << "min value:\t" << Fixed::min(a, b) << std::endl;
	std::cout << "max value:\t" << Fixed::max(a, b) << std::endl;
	std::cout << "const min:\t" << Fixed::min(c, d) << std::endl;
	std::cout << "const max:\t" << Fixed::max(c, d) << std::endl;
}
