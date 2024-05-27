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

        void pairAndSort(std::vector<int>& vec);

        std::vector<int>::iterator prev(std::vector<int>::iterator it, int n);
        std::vector<int>::iterator next(std::vector<int>::iterator it, int n);

};

#endif