#include <iostream>
#include <cmath>

double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;
    
    std::cout << "Enter coordinates of point 1 (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of point 2 (x2 y2): ";
    std::cin >> x2 >> y2;
    
    double distance = calculateDistance(x1, y1, x2, y2);
    std::cout << "The distance between the two points is: " << distance << std::endl;

    return 0;
}