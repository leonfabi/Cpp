#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() > 1) {
        pairAndSort(vec);
        recursiveSortPairsByMax(vec, 0, vec.size() / 2 - 1);
        std::vector<int> main_chain;
        std::vector<int> pend;
        splitIntoMainChainAndPend(vec, main_chain, pend);
        insertPendElements(main_chain, pend);
        std::copy(main_chain.begin(), main_chain.end(), vec.begin());
    }
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

void PmergeMe::recursiveSortPairsByMax(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    recursiveSortPairsByMax(vec, left, mid);
    recursiveSortPairsByMax(vec, mid + 1, right);

    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (vec[2 * i + 1] <= vec[2 * j + 1]) {
            temp.push_back(vec[2 * i]);
            temp.push_back(vec[2 * i + 1]);
            i++;
        } else {
            temp.push_back(vec[2 * j]);
            temp.push_back(vec[2 * j + 1]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(vec[2 * i]);
        temp.push_back(vec[2 * i + 1]);
        i++;
    }

    while (j <= right) {
        temp.push_back(vec[2 * j]);
        temp.push_back(vec[2 * j + 1]);
        j++;
    }

    for (int k = left; k <= right; ++k) {
        vec[2 * k] = temp[2 * (k - left)];
        vec[2 * k + 1] = temp[2 * (k - left) + 1];
    }
}


void PmergeMe::splitIntoMainChainAndPend(std::vector<int>& vec, std::vector<int>& main_chain, std::vector<int>& pend) {
    int size = vec.size();
    bool has_stray = (size % 2 != 0);

    for (int i = 0; i < size - (has_stray ? 1 : 0); i += 2) {
        main_chain.push_back(vec[i + 1]);
        pend.push_back(vec[i]);
    }

    if (has_stray) {
        pend.push_back(vec[size - 1]);
    }
}


void PmergeMe::insertPendElements(std::vector<int>& main_chain, std::vector<int>& pend) {
    std::vector<int> jacobsthal = generateJacobsthalSequence(pend.size());
    main_chain.insert(main_chain.begin(), pend[0]);
    for (size_t idx = 1; idx < pend.size(); ++idx) {
        size_t j = jacobsthal[idx] - 1;
        j = std::min(j, pend.size() - 1);

        while (j >= static_cast<size_t>(jacobsthal[idx - 1])) {
            std::vector<int>::iterator it = std::upper_bound(main_chain.begin(), main_chain.end(), pend[j]);
            main_chain.insert(it, pend[j]);
            if (j == 0) break;
            --j;
        }
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    if (n >= 1) jacobsthal.push_back(1);
    if (n >= 2) jacobsthal.push_back(3);

    int j = 3;
    while (jacobsthal.size() < static_cast<size_t>(n)) {
        int size = jacobsthal.size();
        j = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        jacobsthal.push_back(j);
    }
    return jacobsthal;
}