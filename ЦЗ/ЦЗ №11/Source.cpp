#include <iostream>
#include <algorithm>
#include <cstdlib>

int main() {
    int N;
    std::cout << "Enter the number of cities (N): ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "The number of cities must be positive.\n";
        return 0;
    }

    int x[1000], y[1000];

    std::cout << "Enter city coordinates (x y):\n";
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::sort(x, x + N);
    std::sort(y, y + N);

    int capital_x = x[N / 2];
    int capital_y = y[N / 2];

    long long total_distance = 0;
    for (int i = 0; i < N; i++) {
        total_distance += std::abs(x[i] - capital_x) + std::abs(y[i] - capital_y);
    }

    std::cout << "\nCoordinates of the optimal capital: (" << capital_x << ", " << capital_y << ")\n";
    std::cout << "Sum of distances to all cities: " << total_distance << "\n";

    return 0;
}
