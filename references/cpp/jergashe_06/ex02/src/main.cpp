#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

Base* generate() {
	int i = std::rand() % 3;

	if (i == 0) {
		std::cout << GREEN_TXT << "A was randonmly generated" << DEFAULT_TXT << std::endl;
		return new A();
	} else if (i == 1) {
		std::cout << GREEN_TXT << "B was randonmly generated" << DEFAULT_TXT << std::endl;
		return new B();
	} else if (i == 2) {
		std::cout << GREEN_TXT << "C was randonmly generated" << DEFAULT_TXT << std::endl;
		return new C();
	} else
		return NULL;
}

void identify(Base* p) {
	std::cout << YELLOW_TXT << "\t\tIdentify by pointer:" << DEFAULT_TXT << std::endl;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << BLUE_TXT << "Actual type is: A" << DEFAULT_TXT << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << BLUE_TXT << "Actual type is: B" << DEFAULT_TXT << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << BLUE_TXT << "Actual type is: C" << DEFAULT_TXT << std::endl;
	else
		std::cerr << RED_TXT << "bad cast" << DEFAULT_TXT << std::endl;
}

void identify(Base& p) {
	std::cout << YELLOW_TXT << "\t\tIdentify by reference:" << DEFAULT_TXT << std::endl;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE_TXT << "Actual type is: A" << DEFAULT_TXT << std::endl;
		return;
	} catch (const std::exception& e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BLUE_TXT << "Actual type is: B" << DEFAULT_TXT << std::endl;
		return;
	} catch (const std::exception& e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BLUE_TXT << "Actual type is: C" << DEFAULT_TXT << std::endl;
		return;
	} catch (const std::exception& e) {
		std::cerr << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
		return;
	}
}

int main() {
	Base* ptr = NULL;
	Base* tmp;

	std::srand(std::time(NULL));

	ptr = generate();
	std::cout << " - is a pointer type" << std::endl;
	tmp = generate();
	Base& ref = *tmp;
	std::cout << " - is a reference type" << std::endl;

	identify(ptr);
	identify(ref);

	delete ptr;
	delete tmp;
	// system("leaks dynamic_cast");
	return 0;
}
