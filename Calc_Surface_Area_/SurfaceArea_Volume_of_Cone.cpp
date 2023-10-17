// copyright (c) 2023. Meshach Wallace
// Oct. 2023. Meshach Wallace
// Calculate Surface Area and Volume of Cone
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

double calculateConeVolume(double radius, double height) {
    if (radius <= 0 || height <= 0) {
        throw std::invalid_argument("Radius and height must be positive numbers.");
    }
    return (1.0 / 3.0) * M_PI * std::pow(radius, 2) * height;
}

double calculateConeSurfaceArea(double radius, double height) {
    if (radius <= 0 || height <= 0) {
        throw std::invalid_argument("Radius and height must be positive numbers.");
    }
    double slant_height = std::sqrt(std::pow(radius, 2) + std::pow(height, 2));
    return M_PI * radius * (radius + slant_height);
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < 3; i++) {
        double radius, height;

        try {
            std::cout << "Enter the radius of the cone: ";
            std::cin >> radius;
            std::cout << "Enter the height of the cone: ";
            std::cin >> height;

            double volume = calculateConeVolume(radius, height);
            double surface_area = calculateConeSurfaceArea(radius, height);

            std::cout << "Volume of the cone: " << volume << std::endl;
            std::cout << "Surface Area of the cone: " << surface_area << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid input: " << e.what() << std::endl;
            i--;  // Decrement i to repeat the loop for valid input.
        }
    }

    return 0;
}
