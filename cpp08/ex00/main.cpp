#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try {
        std::vector<int>::iterator found = easyfind(numbers, 30);
        std::cout << "Found the number: " << *found << std::endl;
        found = easyfind(numbers, 100); // This should throw an exception
        std::cout << "Found the number: " << *found << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
