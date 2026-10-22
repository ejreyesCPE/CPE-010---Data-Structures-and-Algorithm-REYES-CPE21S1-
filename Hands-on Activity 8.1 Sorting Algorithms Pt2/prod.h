#ifndef PROD_H
#define PROD_H

#include <iostream>
#include <cstdlib>
#include <ctime>

const int ArraySize = 100;

template <typename T>
void generateRandomArray(T arr[], int size) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

template <typename T>
void shellSort(T arr[], int arrSize) {
    int gap, i, j;
    T temp;

    gap = arrSize / 2;
    while (gap > 0) {
        for (i = gap; i < arrSize; i++) {
            temp = arr[i]; 
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; // shift up by the gap
                j -= gap;
            }
            arr[j] = temp; // drop it into place
        }
        gap /= 2; // shrink the gap each pass (medyo iba process neto)
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int i, j, k;

    T* leftArr = new T[leftSize];
    T* rightArr = new T[rightSize];

    for (i = 0; i < leftSize; i++) leftArr[i] = arr[left + i];
    for (j = 0; j < rightSize; j++) rightArr[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i]; // take from the left half
            i++;
        } else {
            arr[k] = rightArr[j]; // take from the right half
            j++;
        }
        k++;
    }

    while (i < leftSize) { arr[k] = leftArr[i]; i++; k++; }  // leftover left elements
    while (j < rightSize) { arr[k] = rightArr[j]; j++; k++; } // leftover right elements

    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left >= right) return; // base case, 0 or 1 element left

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);      // sort the left half
    mergeSort(arr, mid + 1, right); // sort the right half
    merge(arr, left, mid, right);   // merge them back together
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high]; // last element chosen as pivot
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]); // pivot lands in its final spot
    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low >= high) return; // 0 or 1 element, nothing to do

    int pivotPos = partition(arr, low, high);
    quickSort(arr, low, pivotPos - 1);  // left sub list
    quickSort(arr, pivotPos + 1, high); // right sub list
}

#endif