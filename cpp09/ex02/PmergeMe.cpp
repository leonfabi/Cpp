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

void PmergeMe::merge(std::vector<int>& vec, int left, int middle, int right) {
    int leftSize = middle - left +1;
    int rightSize = right - middle;

    std::vector<int> leftVector(leftSize);
    std::vector<int> rightVector(rightSize);

    for (int i = 0; i < leftSize; i++)
        leftVector[i] = vec[left + i];
    for (int i = 0; i < rightSize; i++)
        rightVector[i] = vec[middle + 1 + i];
    
    int leftIndex = 0, rightIndex = 0, mergedIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftVector[leftIndex] <= rightVector[rightIndex]) {
            vec[mergedIndex] = leftVector[leftIndex];
            leftIndex++;
        } else {
            vec[mergedIndex] = rightVector[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize) {
        vec[mergedIndex] = leftVector[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize) {
        vec[mergedIndex] = rightVector[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}

// void PmergeMe::sortList(std::list<int>& list) {
//     if (list.size() > 1) {
//         std::list<int> left(list.begin(), std::next(list.begin(), list.size() / 2));
//         std::list<int> right(std::next(list.begin(), list.size() / 2), list.end());

//     }
// }