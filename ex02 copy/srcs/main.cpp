# include "PmergeMe.hpp"

bool checkNumberStr(char *input)
{
	for (int i = 0; i < strlen(input); i++) {
		std::cout << input[i] << std::endl;
		if(isdigit(input[i]) == false)
			return false;
	}
	return true;
}

void printInteger(int num)
{
	std::cout << num << " |";
}

template<typename Container>
void printContainer(Container &input)
{
	std::for_each(input.begin(), input.end(), printInteger);
}
// void printContainer(std::vector<int> &input)
// {
// 	std::for_each(input.begin(), input.end(), printInteger);
// }

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
	printContainer(darr);

	std::cout << "Before mergeSort"; printContainer(varr); std::cout << std::endl;
	// auto vec_start = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point vec_start = std::chrono::steady_clock::now();
	Vpmerge_me(varr);
	// auto vec_end = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point vec_end = std::chrono::steady_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(vec_end - vec_start);
	std::cout << "After mergeSort"; printContainer(varr); std::cout << std::endl;
	// std::cout << "time taken for V_mergeSort " << (float)((float)(vec_end - vec_start)/ CLOCKS_PER_SEC);
	std::cout << "time taken for V_mergeSort " << duration.count();

	// clock_t vec_start = clock();
	// mergeSort(varr, varr[varr.size()/2]);
	// clock_t vec_start = clock();
	// std::cout << "After mergeSort"; printContainer(varr); std::cout << std::endl;
	// printContainer (varr);
}