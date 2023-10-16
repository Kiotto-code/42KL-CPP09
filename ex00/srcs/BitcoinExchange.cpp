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

void BitcoinExchange::setAddress(const std::string & address)
{
	this->_address = address;
}

void BitcoinExchange::dictCat(const std::string & address)
{
	std::ifstream file;
	std::string temp;
	std::list<std::string> rate_line;
	// std::string rate_map;
	std::string line;

	file.open(address);
	if (!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return ;
	}

	//each line in file was putted into line ()
	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::cout << line << std::endl;
		std::cin.get();
		while (std::getline(ss, temp, ','))
			rate_line.push_back(temp);
		(this->dict)[temp[0]]
	}
	std::cout << rate_map << std::endl;
	file.close();
}
