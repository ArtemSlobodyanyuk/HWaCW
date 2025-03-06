#include <iostream>
#include <cmath>

struct vector {
	int size, capacity;
	int* data;

	long index(int val) {
		int rv = -1;
		for (int i = 0; i < size; ++i)
			if (data[i] == val)
				return i;
		return rv;
	}
};

int main() {

	int s = 0;
	int c = 0;
	int A[3]{0, 0, 0};
	int B[3]{0, 0, 0};

	std::cout << "Point A. Enter the values ​​of x, y, z: " << std::endl;
	std::cin >> A[0] >> A[1] >> A[2];
	std::cout << "Point B. Enter the values ​​of x, y, z: " << std::endl;
	std::cin >> B[0] >> B[1] >> B[2];
	std::cout << "Enter size: " << std::endl;
	std::cin >> s;
	std::cout << "Enter capacity: " << std::endl;
	std::cin >> c;

	double d = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2) + pow(B[2] - A[2], 2));


	std::cout << "Distance: " << d << std::endl;

	vector v = { s, c, new int[5] {1, 2, 3, 4, 5} };

	std::cout << "Index of 4: " << v.vector::index(4) << std::endl;
	std::cout << "Index of 5: " << v.vector::index(5) << std::endl;


	return 0;
