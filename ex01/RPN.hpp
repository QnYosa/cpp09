#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <list>

bool		check_numbers(std::string);
bool		check_values(std::string);
char 		find_sign(std::string &arg, int &pos);
void		fill_stack(std::string arg, std::stack<std::string, std::list<std::string> > &stack);
void		recursive_fill(std::string &arg, std::stack<std::string, std::list<std::string> > &stack);
std::string	find_operation(std::string operation, char sign);
int			add(int a, int b);
int			multiply(int a, int b);
int			substract(int a, int b);
int			divide(int a, int b);
int			solve(std::stack<std::string, std::list<std::string> > &stack);

#endif