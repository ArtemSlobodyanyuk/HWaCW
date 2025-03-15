#include <iostream>

void findWays(int N) {
    int count = 0;

    
    for (int k = 1; k * (k + 1) / 2 <= N; k++) {
        
        int numerator = N - k * (k - 1) / 2;

        if (numerator % k == 0) {
            int a = numerator / k;

            if (a > 0) { 
                count++;
                std::cout << "Way " << count << ": ";

                for (int i = 0; i < k; i++) {
                    std::cout << (a + i);
                    if (i < k - 1) std::cout << " + ";
                }
                std::cout << " = " << N << std::endl;
            }
        }
    }

    std::cout << "Total number of ways: " << count << std::endl;
}

int main() {
    int N;
    std::cout << "Enter a natural number: ";
    std::cin >> N;

    findWays(N);

    return 0;
}
