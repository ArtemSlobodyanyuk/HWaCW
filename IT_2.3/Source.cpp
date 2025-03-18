#include <iostream>

int gcd(int m, int n) {
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main() {
    int m, n;
    std::cout << "Enter two numbers: ";
    std::cin >> m >> n;

    std::cout << "GCD(" << m << ", " << n << ") = " << gcd(m, n) << std::endl;
    return 0;
}