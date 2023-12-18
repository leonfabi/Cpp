#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <stack>
template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void) {}
		MutantStack(const MutantStack& src)
		{
			return src;
		}
		~MutantStack() {}
		MutantStack &operator=(MutantStack const &src)
		{
			(void) src;
			return *this;
		}
		iterator begin()
		{
			return std::stack<T>::container.begin();
		}
		iterator end()
		{
			return std::stack<T>::container.end();
		}
};

#endif