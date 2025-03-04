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
	int x[2]{ 0, 0 };
	int y[2]{ 0, 0 };
	int z[2]{ 0, 0 };

	std::cin >> x[0];
	std::cin >> y[0];
	std::cin >> z[0];
	std::cin >> x[1];
	std::cin >> y[1];
	std::cin >> z[1];
	std::cin >> s;
	std::cin >> c;

	double d = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2) + pow(z[1] - z[0], 2));


	std::cout << "Distance: " << d << std::endl;

	vector v = { s, c, new int[5] {1, 2, 3, 4, 5} };

	std::cout << "Index of 4: " << v.vector::index(4) << std::endl;
	std::cout << "Index of 5: " << v.vector::index(5) << std::endl;


	return 0;
}
