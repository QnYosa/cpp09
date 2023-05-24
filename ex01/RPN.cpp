#include "RPN.hpp"

bool is_a_sign(char c)
{
	if (c == '+' || c == '-' ||c == '*' ||c == '/')
		return (true);
	return (false);
}

int	valid_signs(std::string &str)
{
	char last = 'F';
	for (int i = 0; str[i]; i++)
	{
		// if (is_a_sign(str[i]))
		// 	last = 
		if (is_a_sign(str[i]) && is_a_sign(last))
			return (-1);
	}
	return (0);
}

bool	check_values(std::string arg)
{
	for (int i = 0; arg[i]; i++)
		if (!isdigit(arg[i]) && is_a_sign(arg[i]) == false && !isspace(arg[i]))
		{
			std::cout << arg[i] << std::endl;
			return (false);
		}
	return (true);
}

bool check_numbers(std::string arg)
{
	for (;atoi(arg.c_str());)
	{
		int number;
		number = atoi(arg.c_str());
		if (number < 0)
			return (false);
		if (arg.find(" ") == std::string::npos)
			return (true);
		else
			arg = arg.substr(arg.find(" ") + 1);			
	}
	return (true);
}


int	consec_numbers(std::string &line)
{
	int numbers_seen;
	numbers_seen = 0;
	for (int i = 0; line[i]; i++)
	{
		if (is_a_sign(line[i]))
			break;
		if (isdigit(line[i]))
			numbers_seen++;
	}
	return (numbers_seen);
}

void	displayStack(std::stack<std::string, std::list<std::string> > stack)
{
	
	while (stack.size() > 0)
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}

void	add(int &a, int b)			{	a += b;}
void	multiply(int &a, int b)		{	a *= b;}
void	substract(int &a, int b)	{	a -= b;}

int	divide(int &a, int b)
{
	// std::cout << "a = " << a << std::endl;
	// std::cout << "b = " << b << std::endl;
	if (b == 0)
	{
		std::cout << "Error can't divide by 0\n";
		return (-1);
	}
	a /= b;
	return (0);
}