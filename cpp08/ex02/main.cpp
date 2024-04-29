/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:25:52 by fkrug             #+#    #+#             */
/*   Updated: 2024/04/29 11:25:53 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main(void){
    {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    }
    {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(19);
    std::cout << "Top of stack after pushing 5, 17 and 19: " << mstack.top() << std::endl;


    mstack.pop();
    std::cout << "Size after one pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Current stack from bottom to top: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> copiedStack(mstack);
    std::cout << "Copied stack from bottom to top: ";
    for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack from bottom to top: ";
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);
    std::cout << "Using std::stack to display elements (should be in stack order, top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    }
    return 0;
}