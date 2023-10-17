#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <sstream>


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
		int checkFormat(char *);
		// void setAddress(const std::string & address);
		void dictCat(const std::string & address);
	
};

#endif