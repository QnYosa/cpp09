#include "BitcoinExchange.hpp"

// MAP ? 

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return -1;
	}
	std::ifstream file;
	file.open(argv[1]);
	if (!file)
	{
		std::cout << "File does not exists\n";
		return (-1);
	}
	if (valid_Syntaxis(file) < 0)
	{
		std::cout << "Error\n";
		return (-2);
	}
	std::map<int, int>charts;
	fill_charts(charts);
	// read the csv file 
	// add content of csv file to map 
	// loop over the content of the file.
	// convert the date to the android format. 
	// fill the map.
}