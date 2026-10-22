#include <iostream>
#include <algorithm>
#include "prod.h"

int main() {
    int array[ArraySize];
    int shellArr[ArraySize], mergeArr[ArraySize], quickArr[ArraySize];

    generateRandomArray(array, ArraySize);
    displayArray(array, ArraySize);
    std::cout << std::endl;
    std::cout << std::endl;

    std::copy(array, array + ArraySize, shellArr);
    shellSort(shellArr, ArraySize);
    displayArray(shellArr, ArraySize);
    std::cout << std::endl;
    std::cout << std::endl;

    std::copy(array, array + ArraySize, mergeArr);
    mergeSort(mergeArr, 0, ArraySize - 1);
    displayArray(mergeArr, ArraySize);
    std::cout << std::endl;
    std::cout << std::endl;

    std::copy(array, array + ArraySize, quickArr);
    quickSort(quickArr, 0, ArraySize - 1);
    displayArray(quickArr, ArraySize);
    return 0;
}