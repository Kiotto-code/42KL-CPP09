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
	std::string line;
	// std::stringstream line();

	file.open(address);
	if (!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return ;
	}
	while(std::getline(file, line))
	{
		std::cout << line << std::endl;
		std::getline(ss, ',');
	}
	file.close()
}