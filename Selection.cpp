#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[101];
const int INF = 987654321;

void selection(int s, int e) {
	for (int i = s; i < e; i++) {
		int minn = arr[i];
		int minn_point = i;
		for (int j = i+1; j < e; j++) {
			if (minn > arr[j]) {
				minn = min(minn, arr[j]);
				minn_point = j;
			}
		}
		swap(arr[i], arr[minn_point]);
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	selection(0, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}