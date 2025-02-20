#include<iostream>

int main() {

	int n = 0;
	int m = 0;

	std::cout << "Enter two numbers" << std::endl;

	std::cout << "Enter n: ";
	std::cin >> n;

	std::cout << "Enter m: ";
	std::cin >> m;

	for (int i = 0; i < m; i++) {
		for (int a = 0; a < n; a++) {
			std::cout << "+";
		}
		std::cout << std::endl;
	}

	return 0;
}