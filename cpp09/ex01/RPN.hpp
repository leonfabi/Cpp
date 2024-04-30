#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <cctype>
#include <iostream>

class RPN {
    public:
        void calculate(const std::string &str);
    private:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void _add();
        void _subst();
        void _mult();
        void _div();
        std::stack<double> _numbers;

};

#endif