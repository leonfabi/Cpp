#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void sortVector(std::vector<int>& vec);
        // void sortList(std::list<int>& list);
    private:
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void fordJohnsonSort(std::vector<int>& vec, int left_index, int right_index);
        // void fordJohnsonSort(std::list<int>& list);
        void merge(std::vector<int>& vec, int left, int middle, int right);
        // void merge(std::list<int>& left, std::list<int>& right, std::list<int>& merged);

};

#endif