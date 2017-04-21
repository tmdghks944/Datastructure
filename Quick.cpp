#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[6];
int n;
void quick(int left, int right) {
	if (right - left < 1) return;
	int pivot = arr[left + rand() % (right - left + 1)];
	int i = left;
	int j = right;
	while (i <= j) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i > j)break;
		swap(arr[i],arr[j]);
		++i, --j;
	}
	quick(left, j);
	quick(i, right);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quick(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

}