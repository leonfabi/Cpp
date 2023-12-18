#include "MutantStack.hpp"

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void subjectTest(T &cont, string printout)
{
	cout << printout << endl;
	cont.push(5);
	cont.push(17);
	cout << "top: " << cont.top() << endl;
	cont.pop();
	cout << "size: " << cont.size() << endl;
	cont.push(3);
	cont.push(5);
	cont.push(737);
	//[...]
	cont.push(0);

	cont.print();
	std::stack<int> s(cont);
	cout << endl;
}

template <typename T>
void comparisonTest(T &cont, string printout)
{
	cout << printout << endl;
	cont.push_back(5);
	cont.push_back(17);
	cout << "top: " << cont.back() << endl;
	cont.pop_back();
	cout << "size: " << cont.size() << endl;
	cont.push_back(3);
	cont.push_back(5);
	cont.push_back(737);
	//[...]
	cont.push_back(0);
	typename T::iterator it = cont.begin();
	typename T::iterator ite = cont.end();
	++it;
	--it;
	cout << "[ ";
	while (it != ite) {
		cout << *it << " ";
		++it;
	}
	cout << "]" << endl << endl;
}

int my_random(int num_range)
{
	int	num = std::rand() % num_range + 1;
	int sign = (std::rand() % 2);
	return sign ? num : -num;
}

template <typename T>
void fill_rand(T &cont, int size, int range)
{
	for (int i = 0; i < size; ++i)
        cont.push(my_random(range));
}

template <typename T>
void randomTest(T &cont, string printout)
{
	std::srand(unsigned(time(0)));
	cout << printout << endl;

	fill_rand(cont, 100, 1000);

	cont.print();
	cout << endl;
}

int main() {
	MutantStack<int> ms;
	MutantStack<int> ms2;
	std::list<int> l;
	std::vector<int> v;

	subjectTest(ms, "=====Subject PDF=====");
	comparisonTest(l, "========List=========");
	comparisonTest(v, "=======Vector========");
	randomTest(ms2, "=====random Test=====");

	return 0;
}
