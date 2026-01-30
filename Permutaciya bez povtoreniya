#include <iostream>

//--------------------------------------------------------------------
// Пермутация без повторения
// 
//				n! = n*(n-1)*(n-2)*...*3*2*1;
// 
// Генериране на всички възможни подредби на елементи от множество;
// Има подредба;
// Няма повторения;
//--------------------------------------------------------------------

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void print(const int* num, const unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) std::cout << num[i] << ' ';
	std::cout << std::endl;
}

void permutation(int* nums, unsigned int pos, const unsigned int n) {

	if (pos == n) {
		print(nums, n);
		return;
	}

	for (unsigned int i = pos; i < n; ++i) {

		bool used = false;
		for(unsigned int j = pos; j < i; ++j)
			if (nums[i] == nums[j]) {
				used = true;
				break;
			}
		if (used) continue;

		swap(nums[pos], nums[i]);
		permutation(nums, pos + 1, n);
		swap(nums[pos], nums[i]);
	}

}

void main() {
		const unsigned int SIZE = 6;

		int nums[SIZE] = { 1, 2, 1, 4, 5, 6 };

		permutation(nums, 0, SIZE);
}
