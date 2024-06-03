#include "PmergeMe.hpp"

bool parseInput(int argc, char* argv[], std::vector<int>& vector, std::deque<int>& deque) {
    for (int i = 1; i < argc; i++) {
        errno = 0;
        char* endptr;
        long int long_value = std::strtol(argv[i], &endptr, 10);

        if (errno != 0 || endptr == argv[i]) {
            std::cout << "Invalid input: " << argv[i] << "\n";
            return false;
        }
        while (*endptr != '\0') {
            if (!isspace(*endptr)) {
                std::cout << "Invalid input. Don't put several values in one argument: \"" << argv[i] << "\"\n";
                return false;
            }
            ++endptr;
        }
        if (long_value <= 0 || long_value > INT_MAX) {
            std::cout << "Value out of range: " << argv[i] << "\n";
            return false;
        }
        vector.push_back(static_cast<int>(long_value));
        deque.push_back(static_cast<int>(long_value));
    }
    return true;
}


int main(int argc, char* argv[]) {
    int display = 10;
    if (argc < 2) {
        std::cout << "No Input provided\n Correct use: ./PmergeMe <list of positive integers> \n";
        return 1;
    }
    std::vector<int> vector;
    std::deque<int> deque;
    if (parseInput(argc, argv, vector, deque) == false)
        return 1;
    PmergeMe sorter;

    clock_t start_vec = clock();
    sorter.sortVector(vector);
    clock_t end_vec = clock();
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;

    clock_t start_deque = clock();
    sorter.sortDeque(deque);
    clock_t end_deque = clock();
    double elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Before: ";
    for (int i = 1; i < argc && i < display + 1; i++)
        std::cout << argv[i] << " ";
    if (argc > display + 1)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "After (vector): ";
    for (int i = 0; i < static_cast<int>(vector.size()) && i < display; i++)
        std::cout << vector[i] << " ";
    if (vector.size() > static_cast<size_t>(display))
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "After (deque)  : ";
    for (int i = 0; i < static_cast<int>(deque.size()) && i < display; i++)
        std::cout << deque[i] << " ";
    if (deque.size() > static_cast<size_t>(display))
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "Time to process " << vector.size() << " elements with std::vector: " << elapsed_vec << " us\n";
    std::cout << "Time to process " << deque.size() << " elements with std::deque: " << elapsed_deque << " us\n";
}