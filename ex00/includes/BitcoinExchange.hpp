#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
// #include <list>
#include <fstream>
#include <sstream>
#include <cstring>
#include <exception>
#include <time.h> //strptime()

# define GREEN	"\x1B[0;92m"
# define YELLOW	"\x1B[0;93m"
# define BLUE	"\x1B[0;94m"
# define PINK	"\x1B[0;95m"
# define CYAN	"\x1B[0;96m"
# define WHITE	"\x1B[38;5;15m"
# define GREY	"\x1B[38;5;8m"
# define ORANGE	"\x1B[38;5;202m"
# define RED	"\x1B[38;5;160m"
# define RESET	"\033[0m"

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
		static std::string realDate(int date);
		// int checkFormat(std::string);
		// void setAddress(const std::string & address);
		void dictCat(const std::string & address);
		// void dictTxt(const std::string & address);

		//getter
		std::map <int, double> &getDict(void);

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

class tooEarlyBirdError : public std::exception{
	public : const char* what() const throw();
};

time_t checkFormat(std::string date);

void spaceRemoval(std::string &line);

bool isLeapYear(int year);
bool isValidDate(int year, int month, int day);

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