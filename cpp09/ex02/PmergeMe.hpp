#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <ctime>
#include <algorithm>
class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void sortVector(std::vector<int>& vec);
        void sortList(std::list<int>& list);
        void sortDeque(std::deque<int>& deque);
    private:
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void pairAndSort(std::vector<int>& vec);
        void recursiveSortPairsByMax(std::vector<int>& vec, int left, int right);
        void splitIntoMainChainAndPend(std::vector<int>& vec, std::vector<int>& main_chain, std::vector<int>& pend);
        void insertPendElements(std::vector<int>& main_chain, std::vector<int>& pend);

        void pairAndSort(std::deque<int>& deque);
        void recursiveSortPairsByMax(std::deque<int>& deque, int left, int right);
        void splitIntoMainChainAndPend(std::deque<int>& deque, std::deque<int>& main_chain, std::deque<int>& pend);
        void insertPendElements(std::deque<int>& main_chain, std::deque<int>& pend);

        std::vector<int> generateJacobsthalSequence(int n);

};

#endif