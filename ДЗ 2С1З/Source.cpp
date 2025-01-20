#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    std::srand(std::time(nullptr));

    int n;
    std::cout << "Enter the array size: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Must be a positive number.\n";
        return 1;
    }

    std::vector<int> array(n);

    std::cout << "Array before sorting:\n";
    for (int i = 0; i < n; ++i) {
        array[i] = std::rand() % 100;
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    bubbleSort(array);

    std::cout << "Array after sorting:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}