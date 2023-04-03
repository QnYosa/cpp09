#include "PmergeMe.hpp"

void sort(std::vector<int> &vec)
{
	std::vector<int>::iterator it;
	std::multiset<int> multi;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		multi.insert(*it);
	}
	std::multiset<int>::iterator multi_it;
	for (multi_it = multi.begin(); multi_it != multi.end(); multi_it++)
	{
		std::cout << "multi_it -> " << *multi_it << std::endl;
	}
	return ;
}