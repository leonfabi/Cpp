#pragma once

#include <stack>
#include <iostream>
#include <cstdlib>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
		
	public:
		MutantStack() {}
		MutantStack(Container const &a) : std::stack<T, Container>::stack(a) {}
		~MutantStack() {}

		MutantStack	&operator=(Container const& a) {
			std::stack<T, Container>::operator=(a);
		}

		typedef typename std::stack<T, Container>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		iterator				begin(void) { return (this->c.begin()); }
		iterator				end(void) { return (this->c.end()); }

		const_iterator			begin(void) const { return (this->c.begin()); }
		const_iterator			end(void) const { return (this->c.end()); }

		reverse_iterator		rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator		rend(void) { return (this->c.rend()); }

		const_reverse_iterator	rbegin(void) const { return (this->c.rbegin()); }
		const_reverse_iterator	rend(void) const { return (this->c.rend()); }

		void print() const {

			MutantStack::const_iterator first = this->begin();
			MutantStack::const_iterator last = this->end();

			std::cout << "[ ";
			for(; first != last; first++){
				std::cout << *first << " ";
			}
			std::cout << "]" << std::endl;
		}
};

