#include <iostream>
#include <thread>

int total = 0;
void add(int value) {
    total += value;
}

int main() {
    
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << total << std::endl;
    T1.join();

    std::cout << total << std::endl;
    T2.join();

    std::cout << total << std::endl;
    T3.join();

    std::cout << total << std::endl;

    return 0;
}