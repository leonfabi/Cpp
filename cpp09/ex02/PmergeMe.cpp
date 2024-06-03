#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() > 1) {
        pairAndSort(vec);
        std::cout << "VECTOR After pairAndSort: ";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
        recursiveSortPairsByMax(vec, 0, vec.size() / 2 - 1);
        std::cout << "VECTOR After recursiveSortPairsByMax: ";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
        std::vector<int> main_chain;
        std::vector<int> pend;
        splitIntoMainChainAndPend(vec, main_chain, pend);
        std::cout << "VECTOR: After splitIntoMainChainAndPend: Main: ";
        for (size_t i = 0; i < main_chain.size(); i++) {
            std::cout << main_chain[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "VECTOR: Pend: ";
        for (size_t i = 0; i < pend.size(); i++) {
            std::cout << pend[i] << " ";
        }
        std::cout << std::endl;
        insertPendElements(main_chain, pend);
        std::copy(main_chain.begin(), main_chain.end(), vec.begin());
    }
}

void PmergeMe::pairAndSort(std::vector<int>& vec) {
    int size = vec.size();
    bool has_stray = (size % 2 != 0);

    std::vector<int>::iterator end = has_stray ? vec.end() - 1 : vec.end();
    for (std::vector<int>::iterator it = vec.begin(); it != end; it += 2) {
        if (*(it + 1) < * it)
            std::iter_swap(it, it + 1);
    }
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
void PmergeMe::sortList(std::list<int>& lst) {
    if (lst.size() > 1) {
        pairAndSort(lst);
        std::list<int>::iterator it = lst.begin();
        std::cout << "LIST After pairAndSort: ";
        for (; it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        recursiveSortPairsByMax(lst);
        it = lst.begin();
        std::cout << "LIST After recursiveSortPairsByMax: ";
        for (; it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::list<int> main_chain;
        std::list<int> pend;
        splitIntoMainChainAndPend(lst, main_chain, pend);
        it = main_chain.begin();
        std::cout << "LIST: After splitIntoMainChainAndPend: Main: ";
        for (; it != main_chain.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        it = pend.begin();
        std::cout << "LIST: Pend: ";
        for (; it != pend.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        insertPendElements(main_chain, pend);
        lst = main_chain;
    }
}

void PmergeMe::pairAndSort(std::list<int>& lst) {
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it != lst.end() && *next_it < *it) {
            std::iter_swap(it, next_it);
        }
        if (next_it == lst.end()) break;
        ++it;
        ++it;
    }
}

void PmergeMe::sortPairs(std::list<int>& lst, std::list<int>::iterator start, std::list<int>::iterator end) {
    if (start == end || std::distance(start, end) <= 2) {
        return;
    }

    std::list<int>::iterator next = start;
    std::advance(next, 2);
    sortPairs(lst, next, end);

    if (next != end) {
        std::list<int>::iterator nextNext = next;
        std::advance(nextNext, 2);

        int first1 = *start;
        int second1 = *(++start);
        --start;

        int first2 = *next;
        int second2 = *(++next);
        --next;

        if (second1 > second2) {
            *start = first2;
            *(++start) = second2;
            --start;

            *next = first1;
            *(++next) = second1;
            --next;
        }
    }
}

void PmergeMe::recursiveSortPairsByMax(std::list<int>& lst) {
    if (lst.size() < 2) {
        return;
    }
    std::list<int>::iterator end = lst.end();
    if (lst.size() % 2 != 0) {
        --end;
    }
    sortPairs(lst, lst.begin(), end);
}

void PmergeMe::splitIntoMainChainAndPend(std::list<int>& lst, std::list<int>& main_chain, std::list<int>& pend) {
    bool has_stray = (lst.size() % 2 != 0);
    std::list<int>::iterator it = lst.begin();

    while (it != lst.end()) {
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it == lst.end()) break;
        main_chain.push_back(*next_it);
        pend.push_back(*it);
        std::advance(it, 2);
    }

    if (has_stray) {
        pend.push_back(lst.back());
    }
}

void PmergeMe::insertPendElements(std::list<int>& main_chain, std::list<int>& pend) {
    std::vector<int> jacobsthal = generateJacobsthalSequence(pend.size());
    std::list<int>::iterator pend_it = pend.begin();
    main_chain.push_front(*pend_it);
    ++pend_it;

    for (size_t idx = 1; idx < pend.size(); ++idx) {
        size_t j = jacobsthal[idx] - 1;
        j = std::min(j, pend.size() - 1);

        while (j >= static_cast<size_t>(jacobsthal[idx - 1])) {
            std::list<int>::iterator it = main_chain.begin();
            for (; it != main_chain.end(); ++it) {
                if (*pend_it < *it) {
                    break;
                }
            }
            main_chain.insert(it, *pend_it);
            ++pend_it;
            if (pend_it == pend.end()) break;
            if (j == 0) break;
            --j;
        }
    }
}
