#include <iostream>

int main() {
    int a, b;
    std::cout << "Enter two integers (a and b): ";
    std::cin >> a >> b;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;

    return 0;
}
