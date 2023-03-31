#include "BitcoinExchange.hpp"

int	check_value(std::string line)
{
	int pos;

	pos = line.find('|');
	if (line.find('|') == std::string::npos)
		return (-14);
	line = line.substr(pos, line.size() - 1);
	if (atoi(line.c_str()) < 0 || atoi(line.c_str()) > 1000)
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

static int	fill_key(std::string &content, std::string &key)
{
	int pos;

	if (content.find(',') == std::string::npos)
		return(-1);
	pos = content.find(",");
	key = content.substr(0, pos);
	if (key.find('-') != std::string::npos)
		key.erase(key.find('-'), 1);
	if (key.find('-') != std::string::npos)
		key.erase(key.find('-'), 1);
	return (0);
}

static int	fill_value(std::string &content, std::string &value)
{
	int pos;

	if (content.find(',') == std::string::npos)
		return(-1);
	pos = content.find(",");
	value = content.substr(pos + 1, content.size());
	return (0);
}


int	cleanDate(std::string &content, std::string &key, int mode)
{
	key = content;
	if (mode == 1)
	{
		if (key.find('-') != std::string::npos)
			key.erase(key.find('-'), 1);
		if (key.find('-') != std::string::npos)
			key.erase(key.find('-'), 1);
	}
	if (key.find('|') != std::string::npos)
	{
		int pos = key.find('|');
		int size = key.size();
		key.erase(key.find('|'), size - pos);
		// key.erase(key.find('|'), 1);
	}
	return (0);
}
int	fill_charts(std::map<int, int> &charts)
{
	std::ifstream charts_csv;
	charts_csv.open("data.csv");
	if (!charts_csv)
	{
		std::cout << "Files doesnt open\n";
		return (-45);
	}
	std::string content;
	std::string key;
	std::string value;
	while (getline(charts_csv, content))
	{
		fill_key(content, key);
		fill_value(content, value);
		charts.insert(std::pair<int, int>(atoi(key.c_str()), atoi(value.c_str())));
	}
	return (0);
}

int getValue(std::string &line, std::string &value)
{
	if (line.find('|') == std::string::npos)
		return (-153);
	value = line.substr(line.find('|') + 1, line.size() - 1);
	return (0);
}

int findClosestDate(std::string &date, std::map<int, int> &map)
{
	std::map<int, int>::iterator it;

	int lowest_range;
	lowest_range = atoi(date.c_str()) - map.begin()->first;
	int closest = map.begin()->first;
	for (it = map.begin(); it != map.end(); it++)
	{
		if (atoi(date.c_str()) -it->first < lowest_range && atoi(date.c_str()) -it->first >= 0)
		{
			lowest_range = atoi(date.c_str()) - it->first;
			closest = it->first;
		}
	}
	if ( atoi(date.c_str()) -it->first < 0)
		return (-1);
	return (closest);
}

int	finalPrint(int &closest, double number, std::map<int, int> &charts, std::string &rawDate)
{
	int valueChart;
	std::map<int, int>::iterator it;
	it = charts.find(closest);
	valueChart = it->second;
	// std::cout << "number => " << number << std::endl;  
	// std::cout << "ValueChart => " << valueChart << std::endl;  
	// std::cout << "result => " << valueChart * number << std::endl;
	std::cout << rawDate << " => " << valueChart << " " << valueChart * number << std::endl;
	return (0);
}

int	searchAndPrintResult(std::ifstream &wallet, std::map<int, int> &charts)
{
	std::string lineWallet; 
	std::string dateAndroidFormat;
	std::string value;
	std::string raw_date;
	int closest = -1;
	while (getline(wallet, lineWallet))
	{
		cleanDate(lineWallet, raw_date, 0);
		cleanDate(lineWallet, dateAndroidFormat, 1);
		//std::cout << "dateAndroidFormat " << dateAndroidFormat << std::endl;
		getValue(lineWallet, value);
		closest = findClosestDate(dateAndroidFormat, charts);
		// std::cout << "1closest =	" << dateAndroidFormat << std::endl;
		finalPrint(closest, atof(value.c_str()), charts, raw_date);
	}
	if (closest < 0)
		return (-1);
	return (closest);
}

void printCharts(std::map<int, int> &map)
{
	std::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); it++)
		std::cout << "date = " << it->first << " value = " << it->second << std::endl;
}
