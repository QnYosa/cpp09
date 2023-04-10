#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (-1);
	}
	std::string arg;
	arg = argv[1];
	if (check_numbers(arg) == false)
	{
		std::cout << "Negative numbers and numbers above 9 are strictly forbidden" << std::endl;
		return (-1);
	}
	if (check_values(arg) == false)
	{
		std::cout << "invalid caracters\n";
		return (-2);
	}
	// recursive_fill(arg, stack);
	solve(arg);
	// lire en commencant ppar les signes et reperer les deux chiffres a sa gauche.
}