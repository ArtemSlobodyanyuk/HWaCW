#include <iostream>

void pPT(int n) {
    int triangle[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
             
                triangle[i][j] = 1;
            }
            else {
                
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows of Pascal's triangle: ";
    std::cin >> n;

    if (n > 0 && n <= 100) {
        pPT(n);
    }
    else {
        std::cout << "Error: valid range 1-100.\n";
    }

    return 0;
}
