#include "BitcoinExchange.hpp"
// map ? int, int 

int	check_value(std::string line)
{
	int pos;

	pos = line.find('|');
	if (line.find('|') == std::string::npos)
		return (-14);
	line = line.substr(pos, line.size() - 1);
	if (atoi(line.c_str()) < 0)
		return (-13);
	return (0);
}

int	date_format(std::string line)
{
	int pos = 0;
	int number;

	number = atoi(line.c_str());
	if (number < 0)
		return (BAD_YEAR_VALUE);
	pos = line.find('-');
	if (line.find('-') == std::string::npos)
		return(-1);
	line = line.substr(pos + 1, line.size() -1);
	number = atoi(line.c_str());
	if (number < 1 || number > 12)
		return (BAD_MONTH_VALUE);
	pos = line.find('-');
	if (line.find('-') == std::string::npos)
		return(-1);
	line = line.substr(pos + 1, line.size() -1);
	number = atoi(line.c_str());
	if (number < 1 || number > 31)
		return (BAD_DAY_VALUE);
	pos = line.find('-');
	if (line.find('-') != std::string::npos)
		return(-1);
	return (0);
}

int	check_hyphens(std::string &line)
{
	for (int i = 0,  hyphen = 0; line[i]; i++)
	{
		if (line[i] == '|')
			hyphen++;
		if (hyphen > 1)
			return (-1);
	}
	return (0);
}

int	valid_Syntaxis(std::ifstream &file)
{
	std::string content;
	while (getline(file, content))
	{
		if (content.find('|') == std::string::npos)
		{
			return (-1);
		}
		if (check_hyphens(content) != 0)
		{
			return (-2);
		}
		if (date_format(content) != 0)
		{
			return (-3);
		}
		if (check_value(content) != 0)
		{
			return (-23);
		}
		std::cout << content << std::endl;
	}
	return (0);
}

// int	algo(std::map <int, int> &map, int value)
// {
// 	map.find(.)
// 	return 0;
// }

// int main(int argc, char **argv)
// {
// 	// test if file is a file.
// 	//check each line of the file to see if it respect the format 

// 	// fill the map and check all the keys.
// 	// must mutilply the value by the conversion rate.
// 	// transform date format to android date format 2012-03-13 = 20120313

// }