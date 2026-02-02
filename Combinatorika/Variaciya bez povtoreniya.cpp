#include <iostream>

//--------------------------------------------------------------------
// Вариация без повторения
// 
//				n!/(n-k)! = n*(n-1)*...*2*1 / (n-k)*(n-k-1)*...*2*1;
// 
// Генериране на всички възможни подредби на k елемента от n възможни;
// Има подредба;
// Няма повторения;
//--------------------------------------------------------------------

void print(const int* var, const unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) std::cout << var[i] << ' ';
	std::cout << std::endl;
}

void variation(int* nums, unsigned int pos, const unsigned int k, const unsigned int n, int* var, bool* used) {
	if (pos == k) {
		print(var, k);
		return;
	}

	for (unsigned int i = 0; i < n; ++i) {
		if (used[i]) continue;

		var[pos] = nums[i];
		used[i] = true;
		variation(nums, pos + 1, k, n, var, used);
		used[i] = false;
	}
}

void main() {
	const unsigned int SIZE = 6;
	const unsigned int k = 4;

	int nums[SIZE] = { 1, 2, 3, 4, 5, 6 };
	int var[k];
	bool used[SIZE] = { false };

	variation(nums, 0, k, SIZE, var, used);
}
