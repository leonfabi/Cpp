/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:15:57 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 10:19:36 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &old_obj)
{
    *this = old_obj;
}

Serializer& Serializer::operator=(const Serializer &old_obj){
    (void)old_obj;
    return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}