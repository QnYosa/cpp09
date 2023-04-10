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

char find_sign(std::string &arg)
{
	if (arg.empty())
		return ('F');
	char sign;
	for (int i = 0; arg[i]; i++)
	{
		if (is_a_sign(arg[i]) == true)
		{
			sign = arg[i];
			arg = arg.substr(i + 1, arg.size() - 1);
			return (sign);
		}
	}	
	return ('F');
}

static int		find_first_argument(std::string line)
{
	for(int i = 0; line[i]; i++)
	{
		if (isdigit(line[i]))
			return (i);
	}
	return (-1);
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

int	solve(std::string &line)
{
	std::stack<std::string, std::list<std::string> > stack;
	int number;
	char sign;
	std::string to_push;
	while (line.size() != 0)
	{
		int number_seen = consec_numbers(line);
		if (number_seen > 0)
		{
			number = find_first_argument(line);
			to_push = line[number];
			stack.push(to_push);
			line = line.substr(number + 1, line.size() - 1);
		}
		if (number_seen == 2)
		{
			number = find_first_argument(line);
			to_push = line[number];
			stack.push(to_push);
			line = line.substr(number + 1, line.size() - 1);
		}
		sign = find_sign(line);
		find_operation(stack, sign);
		if (is_empty_string(line))
			break;
	}
	displayStack(stack);
	return (0);
} 

std::string	find_operation(std::stack<std::string, std::list<std::string> > &stack, char &sign)
{
	int a, b;
	if (atoi(stack.top().c_str()))
	{
		b = atoi(stack.top().c_str());
		stack.pop();
	}
	else
		return ("fail");
	if (atoi(stack.top().c_str()))
	{
		a = atoi(stack.top().c_str());
		stack.pop();
	}
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
	stack.push(streamResult.str());
	return (streamResult.str());
}

void	displayStack(std::stack<std::string, std::list<std::string> > stack)
{
	
	while (stack.size() > 0)
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}

int	add(int a, int b)
{return (a + b);}
int	multiply(int a, int b)
{	return (a * b);}
int	substract(int a, int b)
{	return (a - b);}
int	divide(int a, int b)
{	return (a / b);}