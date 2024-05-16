#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::ifstream file;
	std::string fileline;

	BitcoinExchange b;

	if (ac != 2)
	{
		std::cout << "Wrong Progam Format: " << "two arguments required" << std::endl;
		return 1;
	}
 	try
	{
		b.dictCat("data.csv");
	}
	catch(wrongFormatException &e)
	{
		std::cerr << "data.csv format error: " << e.what() << '\n';
		exit(1);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	
	file.open(av[1]);
	if(!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return 0;
	}
	std::map <int, double> Bitcoin = b.getDict();

	std::getline(file, fileline);
	if (fileline != "date | value")
	{
		std::cerr << "Error: wrong file format \"Date|Value\"" << std::endl;
		return 1;
	}
	while(std::getline(file, fileline))
	{
		if (fileline.empty())
			continue;
		try{
			std::string temp;
			spaceRemoval(fileline);
			int filedate = checkFormat(std::strtok(const_cast<char *>(fileline.c_str()), "|"));

			errno = 0;
			char * valuestring = std::strtok(NULL, "|");
			if (std::strtok(NULL, "|") != NULL )
				throw wrongFormatException();
			if (errno != 0)
				throw wrongFormatException();
			if (valuestring == NULL)
				throw  badInput();
			double filevalue = std::strtod(valuestring, NULL);
			if (errno != 0)
				throw wrongFormatException();
			if (filevalue < 0)
				throw negativeValue();
			if (filevalue > 1000)
				throw largeNumber();

			if (Bitcoin.empty() || filedate < Bitcoin.begin()->first)
				throw (tooEarlyBirdError());
			if (filedate > std::prev(Bitcoin.end())->first)
				throw (std::runtime_error("Too BIG"));
			std::map<int, double>::iterator it = Bitcoin.lower_bound(filedate);
			if (filedate < it->first)
				it --;
			double evaluated_price = it->second * filevalue;
			std::cout << BitcoinExchange::realDate(filedate) << " => " << filevalue << " = " << evaluated_price << std::endl;
		}
		catch(badInput &e)
		{
			std::cerr << "Error: bad input => " << fileline << std::endl;
		}
		catch(negativeValue &e)
		{
			std::cerr << "Error: not a positive number." << std::endl;
		}
		catch(largeNumber &e)
		{
			std::cerr << "Error: too large a number." << std::endl;
		}
		catch(const std::exception &e )
		{
			std::cerr << e.what() << '\n';
		}

	}
	file.close();

	system("leaks btc");
	return (0);
	(void)ac;
}
