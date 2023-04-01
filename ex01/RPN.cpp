#include "RPN.hpp"

bool is_a_sign(char c)
{
	if (c == '+' || c == '-' ||c == '*' ||c == '/')
		return (true);
	return (false);
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
		if (number > 9 || number < 0)
			return (false);
		if (arg.find(" ") == std::string::npos)
			return (true);
		else
			arg = arg.substr(arg.find(" ") + 1);			
	}
	return (true);
}

// find les signes prendre les deux chiffres et remplir la stack.

char find_sign(std::string &arg, int &pos)
{
	if (arg.empty())
		return ('F');
	for (int i = 0; arg[i]; i++)
	{
		if (is_a_sign(arg[i]) == true)
		{
			pos = i;
			return (arg[i]);
		}
	}	
	return ('F');
}

int		find_first_argument(std::string arg, int signPosition)
{
	int number_seen = 0;
	int index_last_number_seen = 0;
	int i = signPosition;
	if (arg.empty() == true)
		return (-1);
	for (; number_seen < 2 && i >= 0; i--)
	{
		if (isdigit(arg[i]))
		{
			number_seen++;
			index_last_number_seen = i;
		}
	}
	return (index_last_number_seen);
}

void	fill_stack(std::string &arg, std::stack<std::string> &stack)
{
	int signPosition = -1;
	char sign = 'F';
	int first_arg = -1;
	(void)stack;
	for (;arg.c_str();)
	{
		sign = find_sign(arg, signPosition);
		first_arg = find_first_argument(arg, signPosition);
		std::cout << arg.substr(first_arg, signPosition) << std::endl;
		std::cout << sign << std::endl;
		std::cout << find_operation(arg.substr(first_arg, signPosition), sign) << std::endl;
		// add to stack 
		// do the operation 
		// convert the result to a string
		// add to the begging of the first item of the stack.
		break;
	}
}

bool		is_empty_string(std::string &arg)
{
	if (arg.empty())
		return (true);
	for (int i = 0; arg[i]; i++)
	{
		if (isspace(arg[i]) == 0)
			return (false);
	}
	return (true);
}

void	recursive_fill(std::string &arg, std::stack<std::string> &stack)
{
	int signPosition = -1;
	int first_arg = -1;
	find_sign(arg, signPosition);
	first_arg = find_first_argument(arg, signPosition);
	int size = signPosition - first_arg + 1;
	if (is_empty_string(arg) == true)
		return ;
	else if (first_arg == -1)
		return ;
	else
	{
		std::string toPush = arg.substr(first_arg, size);
		arg = arg.erase(first_arg, size);
		recursive_fill(arg, stack);
		stack.push(toPush);
	}
}

std::string	find_operation(std::string operation, char sign)
{
	int a = atoi(operation.c_str());
	std::string secondPart = operation.substr(operation.find(' ') + 1, operation.length() - 1);
	int b = atoi(secondPart.c_str());
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	int result = 0;
	switch(sign)
	{
		case '+':
			result = add(a, b);
			break;
		case '-':
			result = substract(a, b);
			break;
		case '*':
			result = multiply(a, b);
			break;
		case '/':
			result = divide(a, b);
			break;
	}
	std::stringstream streamResult;
	streamResult << result;
	return (streamResult.str());
}

int	add(int a, int b)
{return (a + b);}
int	multiply(int a, int b)
{	return (a * b);}
int	substract(int a, int b)
{	return (a - b);}
int	divide(int a, int b)
{	return (a / b);}