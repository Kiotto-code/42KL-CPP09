#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

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
void insertionSort(Container &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Find the correct position using binary search
        int insertionIndex = binarySearch(arr, 0, j, key);

        // Use insert to add the key at the correct position
        arr.insert(arr.begin() + insertionIndex, key);

        // Erase the original occurrence of the key (if it was moved)
        arr.erase(arr.begin() + i + 1);
    }
}
// Merge sort implementation with the merge-insertion sort optimization
void mergeSort(std::vector<int>& arr, int threshold = 30) {
	int insertion_subsize = INSERTION_SUBSIZE;
    if (arr.size() > threshold) {
        int mid = arr.size() / 2;
        std::vector<int> leftHalf(arr.begin(), arr.begin() + mid);
        std::vector<int> rightHalf(arr.begin() + mid, arr.end());

		threshold = leftHalf.size()/2 > insertion_subsize ? leftHalf.size()/2 : insertion_subsize;
        mergeSort(leftHalf, threshold);
		threshold = rightHalf.size()/2 > insertion_subsize ? rightHalf.size()/2 : insertion_subsize;
        mergeSort(rightHalf, threshold);

        // std::vector<int> arr;
        arr.clear();
        std::vector<int>::iterator it_left = leftHalf.begin();
        std::vector<int>::iterator it_right = rightHalf.begin();

        while (it_left != leftHalf.end() && it_right != rightHalf.end()) {
            if (*it_left < *it_right) {
                arr.push_back(*it_left);
                it_left++;
            } else {
                arr.push_back(*it_right);
                it_right++;
            }
        }

        while (it_left != leftHalf.end()) {
            arr.push_back(*it_left);
            it_left++;
        }

        while (it_right != rightHalf.end()) {
            arr.push_back(*it_right);
            it_right++;
        }

    } else {
        insertionSort(arr);
        // binaryInsertionSort(arr);
    }
}

void mergeSort(std::deque<int>& arr, int threshold = 30) {
	int insertion_subsize = INSERTION_SUBSIZE;
    if (arr.size() > threshold) {
        int mid = arr.size() / 2;
        std::deque<int> leftHalf(arr.begin(), arr.begin() + mid);
        std::deque<int> rightHalf(arr.begin() + mid, arr.end());

		threshold = leftHalf.size()/2 > insertion_subsize ? leftHalf.size()/2 : insertion_subsize;
        mergeSort(leftHalf, threshold);
		threshold = rightHalf.size()/2 > insertion_subsize ? rightHalf.size()/2 : insertion_subsize;
        mergeSort(rightHalf, threshold);

        // std::deque<int> arr;
        arr.clear();
        std::deque<int>::iterator it_left = leftHalf.begin();
        std::deque<int>::iterator it_right = rightHalf.begin();

        while (it_left != leftHalf.end() && it_right != rightHalf.end()) {
            if (*it_left < *it_right) {
                arr.push_back(*it_left);
                it_left++;
            } else {
                arr.push_back(*it_right);
                it_right++;
            }
        }

        while (it_left != leftHalf.end()) {
            arr.push_back(*it_left);
            it_left++;
        }

        while (it_right != rightHalf.end()) {
            arr.push_back(*it_right);
            it_right++;
        }

    } else {
        insertionSort(arr);
        // binaryInsertionSort(arr);
    }
}

template<typename Container>
std::chrono::microseconds pmerge_me(Container &merge_vector)
{
    std::chrono::steady_clock::time_point vec_start = std::chrono::steady_clock::now();
	// mergeSort(merge_vector);
	// mergeSort(merge_vector, merge_vector[merge_vector.size()/2]);
	mergeSort(merge_vector, merge_vector.size()/2);
    std::chrono::steady_clock::time_point vec_end = std::chrono::steady_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(vec_end - vec_start);
    return duration;
}

#endif
