#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    int numbers[] = {340, 30, 20, 40, 50};
    std::vector<int> numbers_vector(numbers, numbers + 5);
    std::list<int> numbers_list(numbers, numbers + 5);
    std::deque<int> numbers_deque(numbers, numbers + 5);


    try {
        std::cout << "Vector:" << std::endl;
        int found = easyfind(numbers_vector, 30);
        std::cout << "Found the number 30 at " << found << std::endl;
        std::cout << "List:" << std::endl;
        found = easyfind(numbers_list, 30);
        std::cout << "Found the number 30 at " << found << std::endl;
        std::cout << "Deque:" << std::endl;
        found = easyfind(numbers_deque, 30);
        std::cout << "Found the number 30 at " << found << std::endl;
        found = easyfind(numbers_vector, 100); 
        std::cout << "Found the number 100 at " << found << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Number not found in the container" << std::endl;
    }

    return 0;
}
