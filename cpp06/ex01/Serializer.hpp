/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:42:39 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 10:16:13 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>

typedef struct{
    int test;
}Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &old_obj);
        ~Serializer();
        Serializer& operator=(const Serializer &old_obj);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif