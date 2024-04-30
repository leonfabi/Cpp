#include "RPN.hpp"

void RPN::calculate(const std::string &str) {
    std::string::const_iterator it;
    for(it=str.begin(); it<str.end();it++){
        if(std::isdigit(*it))
            _numbers.push(*it - '0');
        else {
            switch(*it) {
                case '+':
                    _add();
                    break;
                case '-':
                    _subst();
                    break;
                case '*':
                    _mult();
                    break;
                case '/':
                    _div();
                    break;
                default:
                    std::cerr << "Error: forbidden character" << std::endl;
                    return;
            }
        }
    }
}

void RPN::_add() {

}
void RPN::_subst() {

}
void RPN::_mult() {

}
void RPN::_div() {

}