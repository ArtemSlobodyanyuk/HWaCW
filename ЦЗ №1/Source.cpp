#include <iostream>
#include <ctime>
#include <cstdlib>


int main() {
    int n;
    std::cout << "Enter a value n: ";
    std::cin >> n;

    std::cout << "Triples (a, b, c) that satisfy a^2 + b^2 = c^2 and do not exceed " << n << ":\n";

    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            for (int c = b; c <= n; ++c) {
                if (a * a + b * b == c * c) {
                    std::cout << "(" << a << ", " << b << ", " << c << ")\n";
                }
            }
        }
    }

    return 0;
}