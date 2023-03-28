#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#define CSV "data.csv"
#define BAD_DAY_VALUE 31
#define BAD_MONTH_VALUE 13
#define BAD_YEAR_VALUE 2000

int	check_hyphens(std::string &line);
int	valid_Syntaxis(std::ifstream &file);
int	check_value(std::string line);
int	fill_charts(std::map<int, int> charts);

#endif