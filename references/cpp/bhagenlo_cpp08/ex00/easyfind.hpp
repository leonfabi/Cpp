#pragma once

#include <iostream>
//#include <random>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &t, int n)
{
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw std::exception();
	return (it);
}
