#include <iostream>
#include <vector>

// Insertion sort implementation
void insertionSort(std::vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge sort implementation with the merge-insertion sort optimization
void mergeSort(std::vector<int> &arr, int threshold = 5) {
    if (arr.size() > threshold) {
        int mid = arr.size() / 2;
        std::vector<int> leftHalf(arr.begin(), arr.begin() + mid);
        std::vector<int> rightHalf(arr.begin() + mid, arr.end());

        mergeSort(leftHalf, threshold);
        mergeSort(rightHalf, threshold);

        int i = 0, j = 0, k = 0;

        while (i < leftHalf.size() && j < rightHalf.size()) {
            if (leftHalf[i] < rightHalf[j]) {
                arr[k] = leftHalf[i];
                i++;
            } else {
                arr[k] = rightHalf[j];
                j++;
            }
            k++;
        }

        while (i < leftHalf.size()) {
            arr[k] = leftHalf[i];
            i++;
            k++;
        }

        while (j < rightHalf.size()) {
            arr[k] = rightHalf[j];
            j++;
            k++;
        }
    } else {
        insertionSort(arr);
    }
}

// Example usage
int main() {
    std::vector<int> arr;
    arr.push_back(-12);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(5);
    arr.push_back(-6);
    arr.push_back(7);
    // std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Original array: ";
    for (int i = 0; i < arr.size() ; i++) {
        std::cout << arr[i] << " ";
    }
    // for (int num : arr) {
    //     std::cout << num << " ";
    // }
    std::cout << std::endl;

    mergeSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size() ; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
