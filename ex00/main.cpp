#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return -1;
	}
	std::ifstream wallet;
	wallet.open(argv[1]);
	if (!wallet)
	{
		std::cout << "wallet does not exists\n";
		return (-1);
	}
	// checker la length des mois et des jours et ajouter des 0
	// if (valid_Syntaxis(wallet) < 0)
	// {
	// 	std::cout << "Error\n";
	// 	return (-2);
	// }
	// if (wallet)
	// {
	// 	std::cout << "HEllo\n";
	// }
	std::map<int, double>charts;
	fill_charts(charts); // carre
	std::ifstream wallet2;
	wallet2.open(argv[1]);
	searchAndPrintResult(wallet2, charts);
}
