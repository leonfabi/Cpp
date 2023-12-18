
// #include	"Data.hpp"
#include	"Serializer.hpp"
#include	<iostream>

int main()
{
	Data d;
	d.str.append("hello world");
	void* ptr = Serializer::serialize(&d);
	std::cout << ptr << std::endl;
	Data* data = Serializer::deserialize(ptr);
	std::cout << &d << std::endl;
	std::cout << static_cast<Data*>(ptr)->str << std::endl;
	std::cout << data->str << std::endl;
}