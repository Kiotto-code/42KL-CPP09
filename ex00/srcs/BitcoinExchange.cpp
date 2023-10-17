#include "BitcoinExchange.hpp"
// #include <fstream>

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const std::string & address): _address(address)
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		this->_address = rhs._address;
	}
	return (*this);
}

// void BitcoinExchange::setAddress(const std::string & address)
// {
// 	this->_address = address;
// }

/**
 * @brief 	dictCat is to read the file from the path(e.g. data.csv) and then inset them into the BitcoinExchange 
 * 			Dict std::map 
 * 
 * @param path 
 */
void BitcoinExchange::dictCat(const std::string & path)
{
	std::ifstream file;
	std::string temp;
	std::string rate_line;
	// std::list<std::string> rate_line;
	// std::string rate_map;
	std::string line;

	file.open(path);
	if (!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return ;
	}

	

	//each line in file was putted into line ()
	while(std::getline(file, line))
	{
		insertToMap(line);
	}
	file.close();
}

void BitcoinExchange::insertToMap(std::string line)
{
	char original[line.size() + 1];
	strcpy(original, line.c_str());

	int date = checkFormat(strtok(original, ","));
	double rate = strtod(strtok(NULL, ","), NULL);
	this->dict[date] = rate;
}

int BitcoinExchange::checkFormat(char *date)
{

}