#include "RPN.hpp"

void RPN::calculate(const std::string &str) {
    RPN calculator;
    std::string::const_iterator it;
    double pre, past;
    for(it=str.begin(); it<str.end();it++){
        if(std::isdigit(*it))
            calculator._numbers.push(*it - '0');
        else if (std::isspace(*it))
            continue;
        else {
            if(calculator._numbers.size() < 2){
                std::cerr << "Error" << std::endl;
                return ;
            }
            past = calculator._numbers.top();
            calculator._numbers.pop();
            pre = calculator._numbers.top();
            calculator._numbers.pop();
            switch(*it) {
                case '+':
                    calculator._add(pre, past);
                    break;
                case '-':
                    calculator._subst(pre, past);
                    break;
                case '*':
                    calculator._mult(pre, past);
                    break;
                case '/':
                    if(!calculator._div(pre, past))
                        return;
                    break;
                default:
                    std::cerr << "Error" << std::endl;
                    return;
            }
        }
    }
    if (calculator._numbers.size() != 1){
        std::cerr << "Error: Numbers and operators don't match" << std::endl;
        return ;
    }
    std::cout << calculator._numbers.top() << std::endl;
}

RPN::RPN() {}
RPN::~RPN() {}

void RPN::_add(double pre, double past) {
    _numbers.push(pre + past);
}
void RPN::_subst(double pre, double past) {
    _numbers.push(pre - past);
}
void RPN::_mult(double pre, double past) {
    _numbers.push(pre * past);
}
bool RPN::_div(double pre, double past) {
    if (past == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        return false;
    }
    _numbers.push(pre / past);
    return true;
}