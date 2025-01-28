#include <iostream>
#include <cmath>

bool iP(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    std::cout << "Palindrome numbers of the first hundred, which, when squared, also give a palindrome:\n";

    for (int i = 1; i < 100; ++i) {
        if (iP(i)) {
            int square = i * i;
            if (iP(square)) {
                std::cout << i << "(square: " << square << ")\n";
            }
        }
    }

    return 0;
}
