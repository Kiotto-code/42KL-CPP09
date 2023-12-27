#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

# include <vector>
# include <deque>

# include <iomanip>
# include <stdexcept>
# include <cctype>
# include <string>
// # include <chrono>

// void latentCounter(void *f);


void Vpmerge_me(std::vector<int> &merge_vector);
void insertionSort(std::vector<int> &arr);
void mergeSort(std::vector<int> &arr, int threshold = 5);





#endif