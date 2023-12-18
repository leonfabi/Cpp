#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &array, int searchValue)
{
	typename T::iterator start = array.begin();
	while (start != array.end())
	{
		if (*start == searchValue)
			return (1);
		start++;
	}
	return (0);
}

#endif