#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw std::length_error("Span has reached its maximum capacity.");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::range_error("Not enough elements to find a span.");
    }

    std::vector<int> sortedNumbers(numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = INT_MAX;
    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        int currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::range_error("Not enough elements to find a span.");
    }

    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());

    return maxElement - minElement;
}
