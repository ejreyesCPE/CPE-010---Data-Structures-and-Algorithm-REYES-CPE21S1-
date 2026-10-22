#include <iostream>
#include <cmath>
#include <string>

class Triangle {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c);

    void setSides(double a, double b, double c);

    bool validateTriangle() const;

    double getArea() const;

    double getPerimeter() const;

    std::string classifyTriangle() const;
};

int main() {
    Triangle set1(3, 4, 5);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid Triangle.\n";
        std::cout << "Perimeter: " << set1.getPerimeter() << "\n";
        std::cout << "Area: " << set1.getArea() << "\n";
        std::cout << "Type: " << set1.classifyTriangle() << "\n";
    } else {
        std::cout << "The shape is NOT a valid Triangle. \n";
    }

    std::cout << "\n-----------------------------\n\n";

    Triangle set2(10, 2, 3);
    if (set2.validateTriangle()) {
        std::cout << "The shape is a valid Triangle.\n";
    } else {
        std::cout << "The shape is NOT a valid Triangle. \n";
    }

    return 0;
}

Triangle::Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

void Triangle::setSides(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

bool Triangle::validateTriangle() const {
    return (sideA + sideB > sideC) && 
           (sideA + sideC > sideB) && 
           (sideB + sideC > sideA) &&
           (sideA > 0 && sideB > 0 && sideC > 0);
}

double Triangle::getArea() const {
    if (!validateTriangle()) return 0.0;
    double s = getPerimeter() / 2.0;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::getPerimeter() const {
    if (!validateTriangle()) return 0.0;
    return sideA + sideB + sideC;
}

std::string Triangle::classifyTriangle() const {
    if (!validateTriangle()) {
        return "Invalid Triangle";
    }

    double a = sideA;
    double b = sideB;
    double c = sideC;

    if (a >= b && a >= c) {
        c = sideA;
        a = sideB;
        b = sideC;
    } else if (b >= a && b >= c) {
        c = sideB;
        a = sideA;
        b = sideC;
    }

    double sumOfSquares = (a * a) + (b * b);
    double longestSquare = c * c;

    if (sumOfSquares > longestSquare) {
        return "Acute-angled";
    } else if (sumOfSquares < longestSquare) {
        return "Obtuse-angled";
    } else {
        return "Others (Right-angled)";
    }
}
