#include "PmergeMe.hpp"

// vector, deque, multiset

int	fillVector(std::vector<int> &vec, char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		vec.push_back(atoi(argv[i]));
	}
	return (0);
}

int	fillDeque(std::deque<int> &deq, char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		deq.push_back(atoi(argv[i]));
	}
	return (0);
}

int checkArgs(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		if (atoi(argv[i]) < 0)
			return (-1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	if (checkArgs(argv) < 0)
		return (-1);
	std::vector <int> vec;
	std::deque <int> deq;
	std::multiset<int> multi;
	fillVector(vec, argv);
	fillDeque(deq, argv);
	std::vector<int>::iterator it;
	// for (it = vec.begin(); it != vec.end(); it++)
	// {
	// 	std::cout << "it = " << *it << std::endl;
	// }
	int n =vec.size();
    int threshold = 3; // threshold value for when to switch to insertion sort
    merge_insertion_sort(vec, 0, n - 1, threshold);
    for (int i = 0; i < n; i++)
        std::cout <<vec[i] << " ";
    std::cout << std::endl;

	return (0);
}