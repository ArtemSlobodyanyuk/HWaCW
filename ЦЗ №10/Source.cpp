#include <iostream>

void fMV(int N, int index, int prev, int sum, int product, int vector[]) {
    if (index == N) {
        if (sum == product) {
            for (int i = 0; i < N; i++) {
                std::cout << vector[i] << (i == N - 1 ? "\n" : ", ");
            }
        }
        return;
    }

    for (int num = prev; num <= 20; num++) { 
        vector[index] = num;
        fMV(N, index + 1, num, sum + num, product * num, vector);
    }
}

int main() {
    int N;
    std::cout << "Enter the N value: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "N must be a positive number.\n";
        return 0;
    }

    int vector[20];

    std::cout << "\nMagic vectors for N = " << N << ":\n";
    fMV(N, 0, 1, 0, 1, vector);

    return 0;
}
