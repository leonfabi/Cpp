#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <ctime>
class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void sortVector(std::vector<int>& vec);
        void sortList(std::list<int>& list);
    private:
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void fordJohnsonSort(std::vector<int>& vec, int left_index, int right_index);
        void fordJohnsonSort(std::list<int>& list);
        void mergeInsertSort(std::vector<int>& vec, int left, int right);
        void mergeInsertSort(std::list<int>& list);
        void insertionSort(std::vector<int>& vec, int left, int right);
        void insertionSort(std::list<int>& list);
        std::vector<int> generateJacobsthal(int n);


};

#endif