

#include	"Serializer.hpp"


void*	Serializer::serialize(Data* ptr)
{
	return(static_cast<void*>(ptr)); 
}

Data* 		Serializer::deserialize(void* raw)
{
	return(static_cast<Data*>((void*)raw));
}

// Serializer::Serializer()
// {
// }

// Serializer::~Serializer()
// {
// }