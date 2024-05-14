#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {5, 3, 8, 2, 7, 4, 1, 6};
    // for(int num:arr) {
    //     std::cout << num << " ";
    // }
    // for(int num = 0; arr.end() != nullptr ; num++) {
    //     std::cout << arr[num] << " ";
    // }
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	return 0;
}