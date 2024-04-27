#include "Span.hpp"
#include <iostream>
int main (){
    {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(10);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    {
    try {
        Span sp = Span(20000);
        int minSpan = 3;

        srand(time(NULL));
        for (int i = 0; i < 19999; i++) {
            sp.addNumber(i * minSpan);
        }
        sp.addNumber(60000);
        // sp.addNumber(60003);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    }
}