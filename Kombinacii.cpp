#include <iostream>

//--------------------------------------------------------------------
// Комбинация с повторения
// 
//				(n-k+1)! / k! * (n-1)!;
// 
// Избира к елемента от n възможни;
// Няма подредба;
// Има повторения;
//--------------------------------------------------------------------

void print(const int* comb, const unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) std::cout << comb[i] << ' ';
	std::cout << std::endl;
}

void combination(int* nums, int* comb, unsigned int pos, unsigned int start, const unsigned int k, const unsigned int n) {
	if (pos == k) {
		print(comb, k);
		return;
	}

	for (unsigned int i = start; i < n; ++i) {
		comb[pos] = nums[i];
		combination(nums, comb, pos+1, i+1, k, n);
	}
}

void main() {
	const unsigned int SIZE = 6;
	const unsigned int k = 3;
	int nums[SIZE] = { 1, 2, 3, 4, 5, 6 };
	int comb[k];

	combination(nums, comb, 0, 0, k, SIZE);
}
