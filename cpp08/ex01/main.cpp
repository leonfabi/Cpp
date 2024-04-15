#include "Span.hpp"
#include <iostream>
int main (){
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Outputs the smallest difference
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Outputs the largest difference
    return 0;
}