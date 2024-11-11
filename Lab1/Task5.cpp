#include <iostream>
#include <iomanip> // Для форматування виводу

int main() {
    const double pi = 3.14;
    double R;
    
    std::cout << "Enter the radius (R): ";
    std::cin >> R;
    
    double area = pi * R * R;
    double circumference = 2 * pi * R;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area of circle: " << area << std::endl;
    std::cout << "Circumference of circle: " << circumference << std::endl;
    
    return 0;
}
