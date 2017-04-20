#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[101];
const int INF = 987654321;

void insertion(int s, int e) {
	for (int i = s + 1; i < e; i++) {
		int target = arr[i];
		int target_num = i;
		for (int j = i - 1; j >= 0; j--) {
			if (target > arr[j]) {
				break;
			}
			else {
				swap(arr[target_num--], arr[j]);
			}
		}
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	insertion(0, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}