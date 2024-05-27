#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() > 1)
        pairAndSort(vec);
}

void PmergeMe::pairAndSort(std::vector<int>& vec) {
    int size = vec.size();
    bool has_stray = (size % 2 != 0);

    std::vector<int>::iterator end = has_stray ? prev(vec.end(), 1) : vec.end();
    for (std::vector<int>::iterator it = vec.begin(); it != end; it += 2) {
        if (*(it + 1) < * it)
            std::iter_swap(it, it + 1);
    }
}

std::vector<int>::iterator PmergeMe::prev(std::vector<int>::iterator it, int n) {
    return it - n;
}
std::vector<int>::iterator PmergeMe::next(std::vector<int>::iterator it, int n) {
    return it + n;
}
