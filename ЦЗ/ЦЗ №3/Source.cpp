#include <iostream>

void sOE(int n) {
    bool isPrime[1001];

    
    for (int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false;

    
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    
    std::cout << "Prime numbers to " << n << ":\n";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n = 1000;
    sOE(n);
    return 0;
}
