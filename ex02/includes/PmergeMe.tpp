#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"
// #include <string>
// #include <typeinfo>

// void mergeSort(Container&arr, int threshold);

// template<typename Container>
// void insertionSort(Container &arr) {
//     for (int i = 1; i < arr.size(); ++i) {
//         int key = arr[i];
//         // decltype(arr[i]) key = arr[i];
//         // decltype(arr::value_type) key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

template<typename Container>
int binarySearch(Container &arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Element already present, insert at this position
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // Position to insert the element
}

// Function to perform Binary Insertion Sort
template<typename Container>
// Actually BinaryInsertionSort
void insertionSort(Container &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Find the correct position using binary search
        int insertionIndex = binarySearch(arr, 0, j, key);

        // Move elements to make space for the key
        while (j >= insertionIndex) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at the correct position
        arr[insertionIndex] = key;
    }
}

// Merge sort implementation with the merge-insertion sort optimization
// Merge sort implementation with the merge-insertion sort optimization
template<typename Container>
void mergeSort(Container& arr, int threshold = 30) {
    if (arr.size() > threshold) {
        int mid = arr.size() / 2;
        Container leftHalf(arr.begin(), arr.begin() + mid);
        Container rightHalf(arr.begin() + mid, arr.end());

        mergeSort(leftHalf, threshold);
        mergeSort(rightHalf, threshold);

        // Container arr;
        arr.clear();
        typename Container::iterator it_left = leftHalf.begin();
        typename Container::iterator it_right = rightHalf.begin();

        while (it_left != leftHalf.end() && it_right != rightHalf.end()) {
            if (*it_left < *it_right) {
                arr.insert(arr.end(), *it_left);
                it_left++;
            } else {
                arr.insert(arr.end(), *it_right);
                it_right++;
            }
        }

        while (it_left != leftHalf.end()) {
            arr.insert(arr.end(), *it_left);
            it_left++;
        }

        while (it_right != rightHalf.end()) {
            arr.insert(arr.end(), *it_right);
            it_right++;
        }

    } else {
        insertionSort(arr);
        // binaryInsertionSort(arr);
    }
}

// template<typename Container>
// void mergeSort(Container& arr, int threshold = 30) {
//     if (arr.size() > threshold) {
//         int mid = arr.size() / 2;
//         Container leftHalf(arr.begin(), arr.begin() + mid);
//         Container rightHalf(arr.begin() + mid, arr.end());

//         // std::cout << RED"check:" << demangle(typeid(leftHalf).name()) << std::endl;

//         mergeSort(leftHalf, threshold);
//         mergeSort(rightHalf, threshold);

//         int i = 0, j = 0, k = 0;

//         while (i < leftHalf.size() && j < rightHalf.size()) {
//             if (leftHalf[i] < rightHalf[j]) {
//                 arr[k] = leftHalf[i];
//                 i++;
//             } else {
//                 arr[k] = rightHalf[j];
//                 j++;
//             }
//             k++;
//         }

//         while (i < leftHalf.size()) {
//             arr[k] = leftHalf[i];
//             i++;
//             k++;
//         }

//         while (j < rightHalf.size()) {
//             arr[k] = rightHalf[j];
//             j++;
//             k++;
//         }
//     } else {
//         insertionSort(arr);
//     }
// }

template<typename Container>
std::chrono::microseconds pmerge_me(Container &merge_vector)
{
    std::chrono::steady_clock::time_point vec_start = std::chrono::steady_clock::now();
	mergeSort(merge_vector);
	// mergeSort(merge_vector, merge_vector[merge_vector.size()/2]);
    std::chrono::steady_clock::time_point vec_end = std::chrono::steady_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(vec_end - vec_start);
    return duration;
}

#endif // PMERGEME_TPP
