#include "../include/Serializer.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& src) { (void)src; }

Serializer::~Serializer() { return; }

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Serializer& Serializer::operator=(Serializer const& rhs) {
	(void)rhs;
	return *this;
}

// ************************************************************************** //
//                                    REST                                    //
// ************************************************************************** //

uintptr_t Serializer::serialize(Data* data) { return reinterpret_cast<uintptr_t>(data); }

Data* Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
