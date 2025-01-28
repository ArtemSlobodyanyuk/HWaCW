#include <iostream>

void pF(int n) {
    std::cout << n << " = ";
    bool first = true;

    while (n % 2 == 0) {
        if (!first) std::cout << ", ";
        std::cout << 2;
        n /= 2;
        first = false;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (!first) std::cout << ", ";
            std::cout << i;
            n /= i;
            first = false;
        }
    }

    if (n > 2) {
        if (!first) std::cout << ", ";
        std::cout << n;
    }

    std::cout << std::endl;
}

int main() {
    int number;
    std::cout << "Enter a number to factor: ";
    std::cin >> number;

    if (number > 1) {
        pF(number);
    }
    else {
        std::cout << "The number must be greater than 1.\n";
    }

    return 0;
}
