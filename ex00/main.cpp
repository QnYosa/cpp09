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
	// parsing du fichier txt ou autre.
	// checker partout si le format date est respecte a chaque fois
	// check if value is good 
}