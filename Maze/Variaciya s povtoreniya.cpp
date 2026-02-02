#include <iostream>

//--------------------------------------------------------------------
// Вариация с повторения
// 
//				n^k;
// 
// Генериране на всички възможни подредби на k елемента от n възможни;
// Има подредба;
// Има повторения;
//--------------------------------------------------------------------

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void print(const int* num, const unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) std::cout << num[i] << ' ';
	std::cout << std::endl;
}

void variation(int* nums, unsigned int pos, const unsigned int k, const unsigned int n) {
	if (pos == k) {
		print(nums, k);
		return;
	}

	for (unsigned int i = 0; i < n; ++i) {
		swap(nums[pos], nums[i]);
		variation(nums, pos + 1, k, n);
		swap(nums[pos], nums[i]);
	}

}

void main() {
	
	const unsigned int SIZE = 6;

	int nums[SIZE] = { 1, 2, 3, 4, 5, 6 };

	variation(nums, 0, 3, SIZE);

}
