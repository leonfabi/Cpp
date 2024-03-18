/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:20:34 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 10:40:55 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
    Data testData;
    uintptr_t serializedData = Serializer::serialize(&testData);
    Data* deserializedData = Serializer::deserialize(serializedData);

    testData.test = 423;
    std::cout << "Original data: " << testData.test << std::endl;
    std::cout << "Original Data address: " << &testData << std::endl;
    std::cout << "Serialized data: " << serializedData << std::endl;
    std::cout << "Serialized data in hex: " << std::hex << std::showbase << serializedData << std::endl;
    std::cout << "Deserialized data: " << std::dec << deserializedData->test << std::endl;
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    deserializedData->test = -234;
    std::cout << "Modify the value of deserialized data pointer: " << deserializedData->test << std::endl;
    std::cout << "Value of original Data struct: " << testData.test << std::endl;
    return 0;
}