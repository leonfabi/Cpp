
#include	"Data.hpp"

#ifndef SERIAL_CLASS
# define SERIAL_CLASS

struct Data;
class Serializer
{
private:
	Serializer();
	~Serializer();
public:
	static void*		serialize(Data* ptr);
	static Data* 		deserialize(void* raw);
};


#endif