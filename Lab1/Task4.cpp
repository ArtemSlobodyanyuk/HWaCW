#include <iostream>

int main() {
    double A, B, C;
    std::cout << "Enter the dimensions of the parallelepiped (A, B, C): ";
    std::cin >> A >> B >> C;

    double surface_area = 2 * (A * B + A * C + B * C);
    double volume = A * B * C;

    std::cout << "Surface Area: " << surface_area << std::endl;
    std::cout << "Volume: " << volume << std::endl;

    return 0;
}
