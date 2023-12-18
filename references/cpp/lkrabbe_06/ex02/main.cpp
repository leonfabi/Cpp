#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	switch (rand() % 3)
	{
	case 0:
	{
		std::cout << "generate A" << std::endl;
		return((Base*) new A());
	}
	case 1:
	{
		std::cout << "generate B" << std::endl;
		return((Base*) new B());
	}
	case 2:
	{
		std::cout << "generate C" << std::endl;
		return((Base*) new C());
	}
	default:
		return NULL;
	}
}

void identify(Base* target)
{
	if (dynamic_cast<A*>(target) != 0)
		std::cout << "Pointer has the A Class" << std::endl;
	else if (dynamic_cast<B*>(target) != 0)
		std::cout << "Pointer has the B Class" << std::endl;
	else if (dynamic_cast<C*>(target) != 0)
		std::cout << "Pointer has the C Class" << std::endl;
	else
		std::cerr << "Pointer is not a A B or C class" << std::endl;
}

void identify(Base& target)
{
	try
	{
		throw("Error");
		if (dynamic_cast<A*>(&target))
			std::cout << "Reference has the A Class" << std::endl;
		else if (dynamic_cast<B*>(&target))
			std::cout << "Reference has the B Class" << std::endl;
		else if (dynamic_cast<C*>(&target))
			std::cout << "Reference has the C Class" << std::endl;
		else
			std::cerr << "bad reference" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const char *s)
	{
		std::cout << s << "\n" ;
	}
}

int main(void)
{
	srand(time(NULL));
	Base	*test = NULL;
	identify(test);
	Base	test1;
	identify(test1);
	Base	*ptr = generate();
	std::cout << " (pointer)" << std::endl;
	Base	*tmp = generate();
	Base	&ref = *tmp;
	std::cout << " (reference)" << std::endl;
	identify(ptr);
	identify(*ptr);

	identify(ref);
	identify(&ref);

	delete ptr;
	delete tmp;
	return (0);
}