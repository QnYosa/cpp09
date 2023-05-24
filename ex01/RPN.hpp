#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <list>

#define CANT_DIVIDE_BY_ZERO -1

bool		check_numbers(std::string);
bool		check_values(std::string);
void		add(int &a, int b);
void		multiply(int &a, int b);
void		substract(int &a, int b);
int			divide(int &a, int b);
void		displayStack(std::stack<std::string, std::list<std::string> > stack);
int			valid_signs(std::string &str);

#endif