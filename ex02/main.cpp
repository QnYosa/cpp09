#include "PmergeMe.hpp"

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
	fillVector(vec, argv);
	fillDeque(deq, argv);

	int n =vec.size();
	// std::cout << "Before:	";
    // for (int i = 0; i < n; i++)
	// {
    //     std::cout <<vec[i] << " ";
    //     // std::cout <<deq[i] << " ";
	// }
    std::cout << std::endl;
    int threshold = 3; // threshold value for when to switch to insertion sort
	std::clock_t start = std::clock();
	merge_insertion_sort(vec, 0, n - 1, threshold);
    std::clock_t end = std::clock();
    double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	// std::cout << "After:	";
    // for (int i = 0; i < n; i++)
	// {
    //     std::cout <<vec[i] << " ";
    //     // std::cout <<deq[i] << " ";
	// }
    std::cout << std::endl;
    std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::vector " << elapsed_secs << " us" << std::endl;
	start = std::clock();
	mergeInsertionSortDeque(deq, 0, n - 1, threshold);
	end = std::clock();
	elapsed_secs = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::deque " << elapsed_secs << " us" << std::endl;
	return (0);
}