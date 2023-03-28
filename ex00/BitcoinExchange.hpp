#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#define BAD_DAY_VALUE 31
#define BAD_MONTH_VALUE 13

int	check_hyphens(std::string &line);
int	valid_Syntaxis(std::ifstream &file);

#endif