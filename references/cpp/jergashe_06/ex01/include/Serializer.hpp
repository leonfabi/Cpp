#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// #include <cstdint>
#include <iostream>
#include <string>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

struct Data {
	std::string str;
	int num;
	char ch;
	float fl;
	double dbl;
};

// struct Data2 {
// 	int num;
// 	double dbl;
// 	std::string str;
// 	char ch;
// 	float fl;
// };

class Serializer {
   public:
	~Serializer();
	Serializer();
	Serializer(Serializer const& src);

	Serializer& operator=(Serializer const& rhs);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif