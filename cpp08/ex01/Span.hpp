#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
public:
    Span(unsigned int N);
    ~Span();
    Span& operator=(const Span& other);
    Span(const Span& other);
    void addNumber(int number);
    int shortestSpan(void);
    int longestSpan(void);

private:
    std::vector<int> _numbers;
    unsigned int _max_size;
};

#endif
