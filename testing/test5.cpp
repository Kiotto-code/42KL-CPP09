#include <iostream>
#include <array>

int main() {
    // std::array<int> vec;
	std::array<int,6> vec = {1, 2, 3, 4, 5, 6};
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);

    // Create an iterator pointing to the beginning of the array
    std::array<int, 6>::iterator it = vec.begin();

    // Iterate through the array and print each element
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
