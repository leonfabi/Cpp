#include <iostream>
#include <string>

int	main(int argc, char* argv[])
{
	int	count = 0;
	std::string str=argv[0];

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++count < argc)
		{
			str = argv[count];
			for (size_t i = 0; i < str.length(); i++)
				str[i] = std::toupper(str[i]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}