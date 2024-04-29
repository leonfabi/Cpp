#include "Span.hpp"

Span::Span(unsigned int N) : _max_size(N) {
    _numbers.reserve(N);
}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _max_size = other._max_size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() < _max_size) {
       _numbers.push_back(number);
    }
    else
        throw std::length_error("Span has reached its maximum capacity.");
}

int Span::shortestSpan(void) {
    if (_numbers.size() < 2) {
        throw std::range_error("Not enough elements to find a span.");
    }

    int minSpan = INT_MAX;
    int currentSpan = 0;
    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

int Span::longestSpan(void) {
    if (_numbers.size() < 2) {
        throw std::range_error("Not enough elements to find a span.");
    }

    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());

    return maxElement - minElement;
}

