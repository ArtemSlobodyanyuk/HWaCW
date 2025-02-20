#include<iostream>

int main() {

	int n = 0;
	int m = 0;
	int k = 0;

	std::cout << "Enter two numbers" << std::endl;

	std::cout << "Enter n: ";
	std::cin >> n;

	std::cout << "Enter m: ";
	std::cin >> m;

	std::cout << "Enter k: ";
	std::cin >> k;

	if (m < 2 * k) {
		std::cout << "The width of the frame is greater than its height." << std::endl;
	}
	else {
		for (int i = 0; i < k; i++) {
			for (int a = 0; a < n; a++) {
				std::cout << "+";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < m - 2 * k; i++) {
			for (int a = 0; a < k; a++) {
				std::cout << "+";
			}
			for (int a = 0; a < n-2*k; a++) {
				std::cout << " ";
			}
			for (int a = 0; a < k; a++) {
				std::cout << "+";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < k; i++) {
			for (int a = 0; a < n; a++) {
				std::cout << "+";
			}
			std::cout << std::endl;
		}
	};
	
	return 0;
}