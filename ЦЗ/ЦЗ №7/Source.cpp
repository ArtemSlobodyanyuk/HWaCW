#include <iostream>

bool iP(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void fPP(int n) {
    std::cout << "Pairs of twin primes in a range [" << n << ", " << 2 * n << "]:\n";

    for (int i = n; i <= 2 * n - 2; ++i) {
        if (iP(i) && iP(i + 2)) {
            std::cout << "(" << i << ", " << i + 2 << ")\n";
        }
    }
}

int main() {
    int n;
    std::cout << "Enter a number n: ";
    std::cin >> n;

    if (n > 0) {
        fPP(n);
    }
    else {
        std::cout << "The number must be greater than 0.\n";
    }

    return 0;
}
