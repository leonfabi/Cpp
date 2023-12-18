#include "easyfind.hpp"

using std::cout;
using std::endl;

namespace {
	int				   num_range = 10;
	const unsigned int cont_size = 10;
}

void print(int &el)
{
	std::cout << el << " ";
}

int my_random()
{
	return std::rand() % num_range + 1;
}

template <typename T>
void fill_rand(T &cont)
{
	std::generate(cont.begin(), cont.end(), my_random);
}

template <typename T>
void mapc(T &cont, void (*f)(int&))
{
	std::for_each(cont.begin(), cont.end(), f);
}

int main(void)
{
	std::srand(unsigned(time(0)));

	std::vector<int> v1(cont_size);
	fill_rand(v1);
	std::list<int> l1(cont_size);
	fill_rand(l1);
	std::deque<int> d1(cont_size);
	fill_rand(d1);

	mapc(v1, print);
	cout << endl;
	mapc(l1, print);
	cout << endl;
	mapc(d1, print);
	cout << endl;

	try
	{
		cout << *(easyfind(v1, 1)) << endl;
		cout << *(easyfind(l1, 1)) << endl;
		cout << *(easyfind(d1, 1)) << endl;
	}
	catch (std::exception &e)
	{
		cout << "Sorry, this element does not exist." << endl;
	}
}