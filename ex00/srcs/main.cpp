#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::ifstream file;
	std::string fileline;

	BitcoinExchange b;

	// std::set_terminate(my_terminate);
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
		std::cerr << e.what() << '\n';
	}
	
	file.open(av[1]);
	if(!file.is_open())
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return 0;
	}
	std::map <int, double> Bitcoin = b.getDict();

	std::getline(file, fileline);
	while(std::getline(file, fileline))
	{
		try{
			char * temp;

			// temp = strcpy(temp, fileline.c_str());
			spaceRemoval(fileline);
			temp = strdup(fileline.c_str());
			// std::cerr << "check:" << "fileline: " << temp << std::endl;

			// std::cerr << "check:" << "filedate: " << "|" <<strtok(temp, "|") << "|"  << std::endl;

			int filedate = checkFormat(strtok(temp, "|"));
			// std::cerr << "check:" << "filedate: " << filedate << std::endl;
			errno = 0;
			char * valuestring = strtok(NULL, "|");
			if (errno != 0)
				throw wrongFormatException();
			if (valuestring == NULL)
				throw  badInput();
			// std::cout << "check:" << valuestring << std::endl;
			double filevalue = strtod(valuestring, NULL);
			if (errno != 0)
				throw wrongFormatException();
			if (filevalue < 0)
				throw negativeValue();
			if (filevalue > 1000)
				throw largeNumber();
			
			// std::cout << '|' << filevalue << '|' << std::endl;
			// std::cout << "next line {}" << std::endl;


			// int currentDate = filedate;
			if (Bitcoin.empty() || filedate < Bitcoin.begin()->first)
				throw (tooEarlyBirdError());
			std::map<int, double>::iterator it = Bitcoin.lower_bound(filedate);
			if (filedate < it->first)
				it --;
			// std::cout << GREEN"check: "RESET << "bitcoin exchange rate * value :" << it->second * filevalue << std::endl;
			double evaluated_price = it->second * filevalue;
			std::cout << BitcoinExchange::realDate(filedate) << " => " << filevalue << " = " << evaluated_price << std::endl;



			free(temp);
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


	return (0);
	(void)ac;
}
