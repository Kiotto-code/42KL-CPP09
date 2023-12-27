#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::vector<int> temp;
	temp.push_back(5);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(5);
	temp.push_back(8);
	temp.push_back(0);

	std::cout << temp[temp.size()/2] << std::endl;
}