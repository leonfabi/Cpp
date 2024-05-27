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
        void merge(std::vector<int>& vec, int left, int middle, int right);
        void merge(std::list<int>& left, std::list<int>& right, std::list<int>& merged);
        void insertionSort(std::vector<int>& vec, int left, int right);
        void insertionSort(std::list<int>& list);
        std::vector<int> generateJacobsthal(int n);


};

#endif