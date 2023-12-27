#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Two arguments should be input" << std::endl;
	}
	else if ((*av) == NULL)
		std::cout << "The argument is empty" << std::endl;
	else
	{
		try
		{
			std::cout << RPN(av[1]) << std::endl;
		}
		catch(const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}