# include "PmergeMe.hpp"

bool checkNumberStr(char *input)
{
	if (std::all_of(input, input + strlen(input), &::isdigit))
		return true;
	else
		return false;
}

void printInteger(int num)
{
	std::cout << num << " ";
}

template<typename Container>
void printContainer(Container &input)
{
	std::cout << " ";
	std::for_each(input.begin(), input.end(), printInteger);
}

template<typename Container>
int checkOrder(Container test)
{
	if (std::is_sorted(test.begin(), test.end()) == true)
	{
		std::cout << GREEN"they are all sort4ed!" << std::endl;
		return (SORTED);
	}
	else
	{
		std::cout << RED"they are all NOT sort4ed!" << std::endl;
		return (UNSORTED);
	}
	std::cout << RESET;
}

template<typename Vector, typename Deque>
void checkEqual(Vector vector, Deque deque)
{
	if (std::equal(vector.begin(), vector.end(), deque.begin()))
		std::cout << GREEN"They are of equal elements value" << std::endl;
	else
		std::cout << RED"They are of different elements value" << std::endl;
	std::cout << RESET;
}

int main(int ac, char **av)
{
	std::vector<int> varr;
	if (ac < 2)
	{
		std::cerr << "The arguments has to be greater than 1" << std::endl;
		return 1;
	}
	if (av == NULL || *av == NULL)
		throw std::runtime_error("Error");
	av++;
	while (*av)
	{
		int num_elem = std::strtol(*av, NULL, 10);
		// int num_elem = atoi(*av);
		if (checkNumberStr(*av) == false)
		{
			std::cout << "The argument is not number" << std::endl;
			return 1;
		}
		else if (num_elem < 0 || num_elem > std::numeric_limits<int>::max())
		{
			std::cout << "The argumentvalue out range" << std::endl;
			return 1;
		}
		// else if (num_elem < 0)
		// {
		// 	std::cout << "The argumentvalue given must be positve" << std::endl;
		// 	return 1;
		// }
		else
		{
			varr.push_back(num_elem);
		}
		av++;
	}
	std::deque<int> darr(varr.begin(), varr.end());
	// std::list<int> larr(varr.begin(), varr.end());

	std::cout << CYAN"\n\n\nTHE ORDER BEFORE CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "Before mergeSort->Vector"; printContainer(varr); std::cout << std::endl;
	// std::cout << RED"The Order Vector ";
	checkOrder(varr);
	std::cout << BLUE;
	std::cout << "Before mergeSort->Deque"; printContainer(darr); std::cout << std::endl;
	// std::cout << RED"The Order Deque ";
	checkOrder(darr);
	std::cout << ORANGE"\n\n\t [   Pmerge Sort Being Executed ....?   ]"RESET;
	std::chrono::microseconds vector_duration = pmerge_me(varr);
	std::chrono::microseconds deque_duration = pmerge_me(darr);
	// std::chrono::microseconds list_duration = pmerge_me(larr);
	// (void) list_duration;
	std::cout << CYAN"\n\n\nTHE ORDER AFTER CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "After mergeSort->Vector"; printContainer(varr); std::cout << std::endl;
	// std::cout << GREEN"The Order Vector ";
	checkOrder(varr);
	std::cout << BLUE;
	std::cout << "After mergeSort->Deque"; printContainer(darr); std::cout << std::endl;
	// std::cout << GREEN"The Order Deque ";
	checkOrder(darr);
	std::cout << CYAN"\n\n\nTHE TIMING TAKEN FOR CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "Time to process a range of " << varr.size() << " elements with std::"<< "vector : " << std::setw(10) << vector_duration.count() << " microseconds" << std::endl;
	std::cout << BLUE;
	std::cout << "Time to process a range of " << darr.size() << " elements with std::" <<"deque  : " << std::setw(10) << deque_duration.count() << " microseconds" << std::endl;
	std::cout << RESET;
	// std::cout << "Time to process a range of " << larr.size() << " elements with std::" <<"deque  : " << std::setw(10) << list_duration.count() << " microseconds" << std::endl;
	// std::cout << RESET;
	checkOrder(varr);
	// checkOrder(larr);
	checkEqual(varr, darr);
	
	// system("leaks -q PmergeMe");
}

// Time to process a range of 3000 elements with std::[..] : 62.14389 us