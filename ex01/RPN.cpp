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

void	recursive_fill(std::string &arg, std::stack<std::string, std::list<std::string> > &stack)
{
	int signPosition = -1;
	int first_arg = -1;
	if (find_sign(arg, signPosition) == 'F' && is_empty_string(arg) == false)
	{
		std::cout << " Error\n";
		exit(0) ;
	}
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

int	solve(std::stack<std::string, std::list<std::string> > &stack)
{
	std::string sign;
	std::string result;
	while (stack.empty() == false)
	{
		// std::cout << "top => " << stack.top() << std::endl;
		sign = stack.top().substr(stack.top().size() - 1, stack.top().length());
		// std::cout << "end => " << sign << std::endl;
		result = find_operation(stack.top(), sign[0]);
		if (result == "fail")
			return (-1);
		stack.pop();
		if ((stack.empty() == true))
			break ;
		result += " " + stack.top();
		stack.top() = result; 
	}
	std::cout << result << std::endl;
	return (0);
} 

std::string	find_operation(std::string operation, char sign)
{
	int a, b;
	if (atoi(operation.c_str()))
		a = atoi(operation.c_str());
	else
		return ("fail");
	std::string secondPart = operation.substr(operation.find(' ') + 1, operation.length() - 1);
	if (atoi(operation.c_str()))
		b = atoi(secondPart.c_str());
	else
		return ("fail");
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
	// std::cout << "salut Stream => " << streamResult.str() << std::endl;
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