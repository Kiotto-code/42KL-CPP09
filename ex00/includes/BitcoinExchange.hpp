#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
// #include <sstream>
#include <time.h> //strptime()

class BitcoinExchange
{
	private:
		std::string _address;
		std::map <int, double> dict;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string & address);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		// setter
		void insertToMap(std::string);
		// int checkFormat(std::string);
		// void setAddress(const std::string & address);
		void dictCat(const std::string & address);
		// void dictTxt(const std::string & address);

		//exception
		// class wrongFormatException : public std::exception{
		// 	public : const char* what() const throw();
		// };
	
};

class wrongFormatException : public std::exception{
			public : const char* what() const throw();
		};
class badInput : public std::exception{
			public : const char* what() const throw();
		};
class negativeValue : public std::exception{
	public : const char* what() const throw();
};
class largeNumber : public std::exception{
	public : const char* what() const throw();
};

int checkFormat(std::string date);


// void	rateCompare(BitcoinExchange &bitcoinRecord,const std::string path)
// {
// 	std::ifstream file;

// 	file.open(path);
// 	if (!file.is_open())
// 	{
// 		std::cerr << "Failed to open the file!" << std::endl;
// 		return ;
// 	}
// 	while (s)
// }

#endif