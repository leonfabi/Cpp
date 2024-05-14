#include "PmergeMe.hpp"
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <ctime>

bool parseInput(int argc, char* argv[], std::vector<int>& vector, std::list<int>& list) {
    for (int i = 1; i < argc; i++) {
        errno = 0;
        char* endptr;
        long int long_value = std::strtol(argv[i], &endptr, 10);
        if (errno != 0) {
            std::cout << "Invalid input: " << argv[i] << "\n";
            return false;
        }
        if (long_value <= 0 || long_value > INT_MAX) {
            std::cout << "Value out of range: " << argv[i] << "\n";
            return false;
        }
        vector.push_back(static_cast<int>(long_value));
        list.push_back(static_cast<int>(long_value));
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No Input provvided \n";
        return 1;
    }
    std::vector<int> vector;
    std::list<int> list;
    if (parseInput(argc, argv, vector, list) == false)
        return 1;
    PmergeMe sorter;

    clock_t start_vec = clock();
    sorter.sortVector(vector);
    clock_t end_vec = clock();
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Before: ";
    for (int i = 1; i < argc && i < 4; i++)
        std::cout << argv[i] << " ";
    if (argc > 4)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "After (vector): ";
    for (int i = 0; i < static_cast<int>(vector.size()) && i < 4; i++)
        std::cout << vector[i] << " ";
    if (vector.size() > 4)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "Time to process with std::vector: " << elapsed_vec << " us\n";

}