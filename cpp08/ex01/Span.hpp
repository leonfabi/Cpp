/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:25:47 by fkrug             #+#    #+#             */
/*   Updated: 2024/04/29 11:25:48 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        size_t count = std::distance(begin, end);
        if (_numbers.size() + count > _max_size) {
            throw std::length_error("Span has reached its maximum capacity.");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

private:
    std::vector<int> _numbers;
    unsigned int _max_size;
};

#endif
