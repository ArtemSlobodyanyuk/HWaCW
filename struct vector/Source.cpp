#include <iostream>

class Vector {
private:
    int* data;
    size_t size;
public:
    Vector(size_t size) : size(size) {
        data = new int[size] {};
    }

    ~Vector() {
        delete[] data;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    size_t n;
    std::cout << "Enter the vector size: ";
    std::cin >> n;

    Vector vec(n);

    std::cout << "Enter the elements of the vector: ";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::cout << "Your vector: ";
    vec.print();

    return 0;
}
