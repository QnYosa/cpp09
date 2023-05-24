#include "RPN.hpp"

int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1; // character is an operator
	return -1;	  // not an operator
}

int operation(int a, int b, char op)
{
	// Perform operation
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
	{
		if (a == 0)
		{
			std::cout << "Error\n";
			exit (-1);
		}
		return b / a;
	}
	else
		return (-1);
}

int postfixEval(std::string postfix, int &result)
{
	int a, b;
	std::stack<int> stk;
	std::string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++)
	{
		if (isOperator(*it) != -1)
		{
			if (stk.empty() == false)
			{
				a = stk.top();
				stk.pop();
			}
			else
			{
				std::cout << "Error\n";
				return (-2);
			}
			if (stk.empty() == false)
			{
				b = stk.top();
				stk.pop();
				stk.push(operation(a, b, *it));
			}
			else
			{
				std::cout << "Error\n";
				return (-2);
			}
		}
		else if (isdigit(*it) > 0)
		{
			stk.push((*it) - 48);
		}
	}
	if (stk.size() != 1)
	{
		std::cout << "Error\n";
		return (-2);
	}
	result = stk.top();
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return (-1);
	}
	std::string arg;
	arg = argv[1];
	if (check_numbers(arg) == false)
	{
		std::cout << "Negative numbers and numbers above 9 are strictly forbidden\n";
		return (-1);
	}
	if (check_values(arg) == false)
	{
		std::cout << "invalid caracters\n";
		return (-2);
	}
	if (valid_signs(arg) < 0)
	{
		std::cout << "Error\n";
		return (-1);
	}
	int result = 0;
	if (postfixEval(arg, result) < 0)
		return (-1);
	std::cout << result << std::endl;
}
