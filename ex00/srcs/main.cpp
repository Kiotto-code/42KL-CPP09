#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::ifstream file;
	std::string fileline;

	BitcoinExchange b;

	// std::set_terminate(my_terminate);
	try
	{
		b.dictCat("data.csv");
	}
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	catch(wrongFormatException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
		std::cin.get();
		file.open(av[1]);
		if(!file.is_open())
		{
			std::cerr << "Failed to open the file!" << std::endl;
			return 0;
		}
		while(std::getline(file, fileline))
		{
			try{
				char * temp;

				// temp = strcpy(temp, fileline.c_str());
				temp = strdup(fileline.c_str());
				// std::cerr << "check:" << "fileline: " << temp << std::endl;

				// std::cerr << "check:" << "filedate: " << "|" <<strtok(temp, "|") << "|"  << std::endl;

				int filedate = checkFormat(strtok(temp, " | "));
				std::cerr << "check:" << "filedate: " << filedate << std::endl;
				errno = 0;
				char * valuestring = strtok(NULL, " | ");
				if (errno != 0)
				{
					std::cerr  << "001" << std::endl;
					throw wrongFormatException();
				}
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
