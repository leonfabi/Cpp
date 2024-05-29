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

    // std::vector<int>::iterator end = has_stray ? prev(vec.end(), 1) : vec.end();
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
        std::cout << "After pairAndSort: ";
        for (; it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        recursiveSortPairsByMax(lst);
        it = lst.begin();
        std::cout << "After recursiveSortPairsByMax: ";
        for (; it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::list<int> main_chain;
        std::list<int> pend;
        splitIntoMainChainAndPend(lst, main_chain, pend);
        it = main_chain.begin();
        std::cout << "After splitIntoMainChainAndPend: ";
        for (; it != main_chain.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        it = pend.begin();
        std::cout << "Pend: ";
        for (; it != pend.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        insertPendElements(main_chain, pend);
        lst = main_chain;
    }
}

// Pair and sort for lists
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

void PmergeMe::recursiveSortPairsByMax(std::list<int>& lst) {
    if (lst.size() <= 2) return;

    // Split the list into two halves
    std::list<int> first_half, second_half;
    std::list<int>::iterator it = lst.begin();
    std::advance(it, lst.size() / 2);

    first_half.splice(first_half.begin(), lst, lst.begin(), it);
    second_half.splice(second_half.begin(), lst, lst.begin(), lst.end());

    // Recursively sort each half
    recursiveSortPairsByMax(first_half);
    recursiveSortPairsByMax(second_half);

    // Merge the two halves based on the second element of each pair
    lst.clear();
    std::list<int>::iterator it1 = first_half.begin();
    std::list<int>::iterator it2 = second_half.begin();

    // Merge sorted pairs based on the second element
    while (it1 != first_half.end() && it2 != second_half.end()) {
        std::list<int>::iterator it1_next = it1;
        std::advance(it1_next, 1);
        std::list<int>::iterator it2_next = it2;
        std::advance(it2_next, 1);

        if (it1_next == first_half.end() || it2_next == second_half.end()) {
            break;
        }

        if (*it1_next <= *it2_next) {
            lst.push_back(*it1);
            lst.push_back(*it1_next);
            std::advance(it1, 2);
        } else {
            lst.push_back(*it2);
            lst.push_back(*it2_next);
            std::advance(it2, 2);
        }
    }

    // Append remaining pairs from first_half
    while (it1 != first_half.end()) {
        std::list<int>::iterator it1_next = it1;
        std::advance(it1_next, 1);
        if (it1_next != first_half.end()) {
            lst.push_back(*it1);
            lst.push_back(*it1_next);
            std::advance(it1, 2);
        } else {
            lst.push_back(*it1);
            std::advance(it1, 1);
        }
    }

    // Append remaining pairs from second_half
    while (it2 != second_half.end()) {
        std::list<int>::iterator it2_next = it2;
        std::advance(it2_next, 1);
        if (it2_next != second_half.end()) {
            lst.push_back(*it2);
            lst.push_back(*it2_next);
            std::advance(it2, 2);
        } else {
            lst.push_back(*it2);
            std::advance(it2, 1);
        }
    }
}

// Split into main chain and pend for lists
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
    main_chain.push_front(*pend_it);  // Insert the first element
    ++pend_it;  // Move to the next element in pend

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
            if (pend_it == pend.end()) break;  // Break if we have inserted all elements
            if (j == 0) break;
            --j;
        }
    }
}