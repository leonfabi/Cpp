#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
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
    private:
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void pairAndSort(std::vector<int>& vec);
        void recursiveSortPairsByMax(std::vector<int>& vec, int left, int right);
        void splitIntoMainChainAndPend(std::vector<int>& vec, std::vector<int>& main_chain, std::vector<int>& pend);
        void insertPendElements(std::vector<int>& main_chain, std::vector<int>& pend);
        void pairAndSort(std::list<int>& lst);
        void sortPairs(std::list<int>& lst, std::list<int>::iterator it, std::list<int>::iterator end);
        void recursiveSortPairsByMax(std::list<int>& lst);
        void splitIntoMainChainAndPend(std::list<int>& lst, std::list<int>& main_chain, std::list<int>& pend);
        void insertPendElements(std::list<int>& main_chain, std::list<int>& pend);
        std::vector<int> generateJacobsthalSequence(int n);

};

#endif