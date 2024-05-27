#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() > 1)
        fordJohnsonSort(vec, 0, vec.size() - 1);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec, int left_index, int right_index) {
    if (left_index < right_index) {
        int mid_index = left_index + (right_index - left_index) / 2;
        fordJohnsonSort(vec, left_index , mid_index);
        fordJohnsonSort(vec, mid_index + 1, right_index);
        merge(vec, left_index, mid_index, right_index);
    }
}


void PmergeMe::sortList(std::list<int>& list) {
    if (list.size() > 1)
        fordJohnsonSort(list);
}

void PmergeMe::fordJohnsonSort(std::list<int>& list) {
    if (list.size() <= 1)
        return;

    std::list<int> left, right;
    std::list<int>::iterator it = list.begin();

    std::advance(it, list.size() / 2);
    left.splice(left.begin(), list, list.begin(), it);
    right.splice(right.begin(), list, list.begin(), list.end());

    fordJohnsonSort(left);
    fordJohnsonSort(right);
    merge(left, right, list);
}

