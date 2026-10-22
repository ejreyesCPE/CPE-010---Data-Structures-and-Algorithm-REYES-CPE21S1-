#include <iostream>

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    double kelvin;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;
    
    double fahrenheit = kelvinToFahrenheit(kelvin);

    std::cout << kelvin << " K is equal to " << fahrenheit << " F" << std::endl;

    return 0;
}