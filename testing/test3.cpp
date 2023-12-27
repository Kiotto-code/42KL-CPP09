#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Create an iterator pointing to the beginning of the vector
    std::vector<int>::iterator it = vec.begin();

    // Iterate through the vector and print each element
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
