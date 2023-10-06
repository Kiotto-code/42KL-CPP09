#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>


class BitcoinExchange
{
	private:
		std::string _address;
		std::map <std::string, std::string> dict;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string & address);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		// setter
		void setAddress(const std::string & address);
		void dictCat(const std::string & address);
	
};

#endif