#include "RPN.hpp"

int	RPN(std::string equation)
{
	std::stack<int> RPN;
	std::string token;
	std::istringstream insert(equation);

	while (insert >> token)
	{
		// std::cout << ORANGE << token << RESET << std::endl;
		if (token.length() != 1)
			throw std::runtime_error("Digit Format Error"); // runtime_error being thrown due to the wrong format being input
		else if (isdigit(token[0]))
			// RPN.push(std::atoi(token.c_str()));
			RPN.push(atoi(token.c_str()));
		else{ // when the token[0] is not digit, checking for "+-*/ "
			if (RPN.empty())
				throw std::runtime_error("Error");
			int lower_elem = RPN.top();
			RPN.pop();

			if (RPN.empty())
				throw std::runtime_error("Error");
			int upper_elem = RPN.top();
			RPN.pop();

			if (token[0] == '+')
				RPN.push(upper_elem + lower_elem);
			else if (token[0] == '-')
				RPN.push(upper_elem - lower_elem);
			else if (token[0] == '*')
				RPN.push(upper_elem * lower_elem);
			else if (token[0] == '/')
				RPN.push(upper_elem / lower_elem);
			else if (token[0] != ' ')
				throw std::runtime_error("Error4"); //anything other than given symbol / digits should be error handled
			// else
			// 	throw std::runtime_error("Error"); //anything other than given symbol / digits should be error handled
				
		}
	}
	if (RPN.size() > 1)
        throw std::runtime_error("Operand Leftover Error");
	return RPN.top();
}