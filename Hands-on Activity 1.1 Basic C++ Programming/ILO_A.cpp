#include <iostream>

class NumberOperations {
public:
    int sumofTwoNumbers(int fNum, int lNum);
    bool isGreater(int A, int B);
    bool logicalOperations(bool a, bool b);
};

int main() {
    NumberOperations ops;
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Sum: " << ops.sumofTwoNumbers(num1, num2) << std::endl;

    std::cout << std::boolalpha; 

    std::cout << "\nIs " << num1 << " greater than " << num2 << "? "
              << ops.isGreater(num1, num2) << std::endl;

    bool boolA, boolB;
    std::cout << "\nEnter two boolean values (1 or 0): ";
    std::cin >> boolA >> boolB;

    bool success = ops.logicalOperations(boolA, boolB);
    std::cout << "Logical operations completed successfully: " << success << std::endl;

    return 0;
}

int NumberOperations::sumofTwoNumbers(int fNum, int lNum) {
    int total = fNum + lNum;
    return total;
}

bool NumberOperations::isGreater(int A, int B) {
    return A > B;
}

bool NumberOperations::logicalOperations(bool a, bool b) {
    std::cout << std::boolalpha;
    std::cout << "\n Results: x`\n";
    std::cout << "A = " << a << ", B = " << b << std::endl;

    std::cout << "A AND B: " << (a && b) << std::endl;
    std::cout << "A OR B: " << (a || b) << std::endl;
    std::cout << "NOT A: " << (!a) << std::endl;
    std::cout << "NOT B: " << (!b) << std::endl;

    return true; 
}