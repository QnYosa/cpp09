#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error" << std::endl;
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
		return(-2);
	}
	std::stack<std::string> stack;
	recursive_fill(arg, stack);
	while (stack.empty() == false)
	{
		std::cout << "top =>" << stack.top() << std::endl;
		stack.pop();
	}
	// lire en commencant ppar les signes et reperer les deux chiffres a sa gauche. 
}