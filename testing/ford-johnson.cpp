#include <iostream>
#include <vector>

void fordJohnsonSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }
		std::cout << "item: " << item << ", pos: " << pos << std::endl;
		std::cin.get();
        if (pos == cycleStart) {
            continue;
        }
		// printf("item: %d, pos: %d\n", item, pos);
		std::cout << "item: " << item << ", pos: " << pos << std::endl;
		std::cin.get();

        while (item == arr[pos]) {
            pos++;
        }
        if (pos != cycleStart) {
            std::swap(item, arr[pos]);
        }

		std::cout << arr(std::begin(arr), std::end(arr)) << std::endl;
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }
            while (item == arr[pos]) {
                pos++;
            }
            if (item != arr[pos]) {
                std::swap(item, arr[pos]);
            }
        }
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 2, 7, 4, 1, 6};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    fordJohnsonSort(arr);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
