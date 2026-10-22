#include <iostream>

int main() {
    double num1, num2, temp;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "\nBefore swapping:\n";
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;

    temp = num1;
    num1 = num2;
    num2 = temp;

    std::cout << "\nAfter swapping:\n";
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}