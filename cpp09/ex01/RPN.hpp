#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <cctype>
#include <iostream>

class RPN {
    public:
        static void calculate(const std::string &str);
    private:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void _add(double pre, double past);
        void _subst(double pre, double past);
        void _mult(double pre, double past);
        bool _div(double pre, double past);
        std::stack<double> _numbers;

};

#endif