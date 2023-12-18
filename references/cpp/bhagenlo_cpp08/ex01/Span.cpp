#include "Span.hpp"

Span::Span(void) : _N(0), _stored(0), _maxSpan(0), _minSpan(INT_MAX) {}

Span::Span(const unsigned int N) : _N(N), _stored(0), _maxSpan(0), _minSpan(INT_MAX) {}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span()
{
	_data.clear();
}

Span	&Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->_data.clear();
		this->_N = span._N;
		this->_stored = span._stored;
		this->_minSpan = span._minSpan;
		this->_maxSpan = span._maxSpan;
		this->_data = span._data;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Span &span)
{
	span.printData(o);
	return (o);
};

void	Span::addNumber(const int n)
{
	if (_stored >= _N)
		throw Span::alreadyFull();
	
	bool added = false;
	int minAcc = INT_MAX;
	for (vecIt it = _data.begin(); it != _data.end(); it++)
	{
		if (n < *it)
		{
			added = true;
			_data.insert(it, n);
			if (it == _data.begin())
				_maxSpan = _data[_data.size() - 1] - n;
			break;
		}
		
	}
	if (!added)
	{
		_data.insert(_data.end(), n);
		_maxSpan = n - _data[0];
	}
	for (vecIt it = _data.begin(); it != _data.end() && it + 1 != _data.end(); it++)
	{
		minAcc = std::min(minAcc, *(it + 1) - *it);
	}
	// std::cout << minAcc << std::endl;
	_minSpan = minAcc;
	_stored++;
}

int		Span::longestSpan(void) const
{
	if (_stored <= 1)
		throw Span::notEnoughNumbers();

	return (_maxSpan);
}

int		Span::shortestSpan(void) const
{

	if (_stored <= 1)
		throw Span::notEnoughNumbers();

	return (_minSpan);
}

void	Span::printData(std::ostream &o, const unsigned int max) const
{
	o << "[ ";
	for (unsigned int i = 0; i < max && i < _stored; i++)
		o << _data[i] << " ";
	if (_stored > max)
		o << "... " << _data[_stored - 1] << " ";
	o << "] (" << _stored << "/" << _N << ")";
}

void	Span::print(void)
{
	std::cout << (*this) << std::endl;
	std::cout << "shortest span: " << this->shortestSpan() << std::endl;
	std::cout << "longest span:  " << this->longestSpan() << std::endl;
}
