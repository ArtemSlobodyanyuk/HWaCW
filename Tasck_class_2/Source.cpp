/* 
(1 + (5 + (6 + (9 + (4 + (10))))))
6 +6
12 + 9
21 + 4
25 + 10
35
*/ 
#include<iostream>
#include<vector>
using vint = std::vector<int>;
using iter = std::vector<int>::iterator;

int sum(vint& a) {
	int s = 0;
	for (int i = 0; i < a.size(); i++) {
		s = s + a[i];
	}
	
	return s;
}

int sum(iter first, iter last) {
	//std::cout << "sum: " << *first << "; " << *(last-1) << std::endl;
	 
	if (first >= last-1) {
		return *first;
	}
	else if (first < last)
	{
		return (*first + sum(first + 1, last));
	}
}


int main() {
	vint a = {1, 5, 6, 9, 4, 10};
	a.push_back(3);
	std::cout << sum(a.begin(), a.end()) << std::endl;



	return 0;
}