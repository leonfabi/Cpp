#include "Span.hpp"

#include <unistd.h>

namespace {
	int range = 10000;
	int small = 50;
	int large = 20000;
}

int my_random(int num_range)
{
	int	num = std::rand() % num_range + 1;
	int sign = (std::rand() % 2);
	return sign ? num : -num;
}

void fill_rand(std::vector<int> &cont, int range)
{
	std::vector<int>::iterator first = cont.begin();
	std::vector<int>::iterator last = cont.end();

	for (; first != last; ++first)
        *first = my_random(range);
}

void	randomSpan(int size, int range, bool uniq)
{
	std::srand(unsigned(time(0)));
	Span	sp(size);

	std::vector<int> v1(size);
	fill_rand(v1, range);
	if (uniq)
	{
		std::sort(v1.begin(), v1.end());
		v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
	}
	sp.fillRange< std::vector<int> >(v1.begin(), v1.end());
	
	sp.print();
}

int main()
{
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.print();
	}
	randomSpan(small, range, false);
	usleep(5346982);
	randomSpan(small, range, true);
	randomSpan(large, range, false);
	randomSpan(large, range, true);
}
