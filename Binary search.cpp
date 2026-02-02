#include <iostream>

int binary_search(int* arr, int x, int l, int r){
	if (l > r) return -1;

	int mid = l + (r - l) / 2;
	if (arr[mid] == x) return mid;
	if (arr[mid] > x) return binary_search(arr, x, l, mid - 1);
	if (arr[mid] < x) return binary_search(arr, x, mid + 1, r);


}

void main() {
	int arr[] = { 1, 3, 5, 7, 9 };
	int n = 5;

	int idx = binary_search(arr, 5, 0, n - 1);

	std::cout << idx << "\n";
}
