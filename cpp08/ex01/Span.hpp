#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> numbers;
    unsigned int max_size;
};

#endif // SPAN_HPP
