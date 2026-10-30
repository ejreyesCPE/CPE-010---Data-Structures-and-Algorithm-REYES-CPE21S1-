#include <iostream>
#include <vector>
#include <thread>


int foundIndex = -1;

void linearSearch(const std::vector<int>& arr, int target, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (arr[i] == target) {
            foundIndex = i;
            return;
        }
    }
}

int main() {
    std::vector<int> numbers = {5, 12, 8, 25, 3, 19, 42, 7, 31, 14};
    int target = 42;
    int mid = numbers.size() / 2;

  
    std::thread T1(linearSearch, std::cref(numbers), target, 0, mid);
    std::thread T2(linearSearch, std::cref(numbers), target, mid, numbers.size());

    T1.join();
    T2.join();

    if (foundIndex != -1) {
        std::cout << "Target " << target << " found at index " << foundIndex << std::endl;
    } else {
        std::cout << "Target " << target << " not found." << std::endl;
    }

    return 0;
}