#include <iostream>

char r[1000];

void rD(const char* n, char d) {
    int j = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] != d) {
            r[j++] = n[i];
        }
    }
    r[j] = '\0';
}

    int main() {
        char number[20];
        char digit;

        std::cout << "Enter number: ";
        std::cin >> number;

        std::cout << "Enter the number to delete: ";
        std::cin >> digit;

        rD(number, digit);

        if (r[0] == '\0') {
            std::cout << "Result: 0" << std::endl;
        }
        else {
            std::cout << "Result: " << r << std::endl;
        }

        return 0;
    }