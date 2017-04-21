#include <iostream>
#include <cstdio>

using namespace std;
int arr[6];
int n;

void mergealgo(int left, int right) {
	int mid = (left + right) / 2;
	int* tmp = (int *)(malloc)((right - left + 1) * sizeof(int));
	int i = left;
	int j = mid + 1;
	int idx = 0;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			tmp[idx] = arr[i];
			i++;
		}
		else {
			tmp[idx] = arr[j];
			j++;
		}
		idx++;
	}
	for (; i <= mid; i++) {
		tmp[idx++] = arr[i];
	}
	for (; j <= right; j++) {
		tmp[idx++] = arr[j];
	}
	for (int pos = 0; pos <= right-left; pos++) {
		arr[pos+left] = tmp[pos];
	}
}


void mergesort(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergesort(left, mid);
		mergesort(mid + 1, right);
		mergealgo(left, right);
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergesort(0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}