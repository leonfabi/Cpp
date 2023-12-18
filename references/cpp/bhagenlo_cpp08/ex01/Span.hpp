#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

class Span
{
	private:
		unsigned int		_N;
		unsigned int		_stored;
		unsigned int		_maxSpan;
		unsigned int		_minSpan;
		std::vector<int>	_data;
		Span(void);

	public:
		Span(const unsigned int N);
		Span(const Span &span);
		virtual ~Span();
		Span	&operator=(const Span &span);

		void	addNumber(const int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	printData(std::ostream &o, const unsigned int max = 10) const;
		void	print(void);

		template<typename T> void	fillRange(typename T::iterator begin, typename T::iterator end);

		class alreadyFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("Span::Exception : data is full");
				}
		};

		class notEnoughNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("Span::Exception : not enough numbers");
				}
		};

};

std::ostream	&operator<<(std::ostream &o, const Span &span);

typedef std::vector<int>::iterator vecIt;

template<typename T> void	Span::fillRange(typename T::iterator begin, typename T::iterator end)
{
	typename T::iterator	it;

	it = begin;
	while (it != end)
	{
		addNumber(*it);
		it++;
	}
}
