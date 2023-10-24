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
	std::string line;

	file.open(path);
	if (!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return ;
	}
	std::getline(file, line);
	while(std::getline(file, line))
	{
		spaceRemoval(line);
		insertToMap(line);
	}
	file.close();
}

void BitcoinExchange::insertToMap(std::string line)
{
	char original[line.size() + 1];
	strcpy(original, line.c_str());

	int date = checkFormat(strtok(original, ","));
	// std::cerr << "check:" << "date: " << date << std::endl;
	// std::cout << "check: " << date << std::endl;
	double rate = strtod(strtok(NULL, ","), NULL);
	this->dict[date] = rate;
}

std::map <int, double> &BitcoinExchange::getDict(void)
{
	return this->dict;
}

int checkFormat(std::string date)
{
	struct tm tm; //for the use of strptime() parameter
	char *ret;

	try
	{
		ret = strptime(date.c_str(), "%Y-%m-%d", &tm); //strptime would return null if the date given is invalid ;).
		if (ret == NULL || *ret != '\0')//when eof it would return a NUL character "\0"
			throw wrongFormatException();
		return tm.tm_year * 10000 + tm.tm_mon * 100 + tm.tm_mday; //return the info in the integer
	}
	catch(wrongFormatException &e)
	{
		// std::cerr << e.what() << '\n';
	}
	return false;
}

void spaceRemoval(std::string &line)
{
	if (line.empty())
		return ;
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
}

const char* wrongFormatException::what() const throw()
{
	return ("Wrong Format Give");
}

const char* badInput::what() const throw()
{
	return ("Wrong File Input");
}

const char* negativeValue::what() const throw()
{
	return ("File Input Negative Value");
}

const char* largeNumber::what() const throw()
{
	return ("The number is too large it exceeds the 1000 max value(0-1000 range)");
}

const char* tooEarlyBirdError::what() const throw()
{
	return ("The input date given is too early for the data.csv (wry)");
}
