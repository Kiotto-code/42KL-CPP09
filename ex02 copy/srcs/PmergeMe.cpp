# include "PmergeMe.hpp"

void Vpmerge_me(std::vector<int> &merge_vector)
{
	mergeSort(merge_vector, merge_vector[merge_vector.size()/2]);
}

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
void mergeSort(std::vector<int> &arr, int threshold) {
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