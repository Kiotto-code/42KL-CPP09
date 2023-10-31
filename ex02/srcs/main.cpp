# include "PmergeMe.hpp"

bool checkNumberStr(char *input)
{
	// for (int i = 0; i < strlen(input); i++) {
	// 	// std::cout << input[i] << std::endl;
	// 	if(isdigit(input[i]) == false)
	// 		return false;
	// }
	// return true;
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
// void printContainer(std::vector<int> &input)
// {
// 	std::for_each(input.begin(), input.end(), printInteger);
// }

template<typename Container>
int checkOrder(Container test)
{
	// for (typename Container::iterator i = test.begin(); i != test.end(); i++)
	// {
		
	// }
	if (std::is_sorted(test.begin(), test.end()) == true)
	{
		std::cout << GREEN"they are all sort4ed!" << std::endl;
		exit(1);
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
		int num_elem = atoi(*av);
		if (checkNumberStr(*av) == false)
		{
			std::cout << "The argument is not number" << std::endl;
			return 1;
		}
		else if (num_elem < 0)
		{
			std::cout << "The argumentvalue given must be positve" << std::endl;
			return 1;
		}
		else
		{
			varr.push_back(num_elem);
		}
		av++;
	}
	std::deque<int> darr(varr.begin(), varr.end());

	std::cout << CYAN"\n\n\nTHE ORDER BEFORE CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "Before mergeSort->Vector"; printContainer(varr); std::cout << std::endl;
	std::cout << RED"The Order Vector ";checkOrder(varr);
	std::cout << BLUE;
	std::cout << "Before mergeSort->Deque"; printContainer(darr); std::cout << std::endl;
	std::cout << RED"The Order Deque ";checkOrder(darr);
	// auto vec_start = std::chrono::steady_clock::now();
	// std::chrono::steady_clock::time_point vec_start = std::chrono::steady_clock::now();
	std::cout << ORANGE"\n\n\t [   Pmerge Sort Being Executed ....?   ]"RESET;
	std::chrono::microseconds vector_duration = pmerge_me(varr);
	std::chrono::microseconds deque_duration = pmerge_me(darr);
	// auto vec_end = std::chrono::steady_clock::now();
	// std::chrono::steady_clock::time_point vec_end = std::chrono::steady_clock::now();
	// std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(vec_end - vec_start);
	std::cout << CYAN"\n\n\nTHE ORDER AFTER CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "After mergeSort->Vector"; printContainer(varr); std::cout << std::endl;
	std::cout << GREEN"The Order Vector ";checkOrder(varr);
	std::cout << BLUE;
	std::cout << "After mergeSort->Deque"; printContainer(darr); std::cout << std::endl;
	std::cout << GREEN"The Order Deque ";checkOrder(darr);
	// std::cout << "time taken for V_mergeSort " << (float)((float)(vec_end - vec_start)/ CLOCKS_PER_SEC);
	// std::cout << "time taken for " << typeid(varr).name() << vector_duration.count();

	std::cout << CYAN"\n\n\nTHE TIMING TAKEN FOR CONTAINERS TO EXECUTE FORD-JOHNSON\n"RESET;
	std::cout << YELLOW;
	std::cout << "time taken for " << "vector : " << vector_duration.count() << " microseconds" << std::endl;
	std::cout << BLUE;
	std::cout << "time taken for " << "deque : " << deque_duration.count() << " microseconds" << std::endl;
	std::cout << RESET;
	checkOrder(varr);
	checkEqual(varr, darr);
	// clock_t vec_start = clock();
	// mergeSort(varr, varr[varr.size()/2]);
	// clock_t vec_start = clock();
	// std::cout << "After mergeSort"; printContainer(varr); std::cout << std::endl;
	// printContainer (varr);
}