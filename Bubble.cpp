#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[101];
const int INF = 987654321;

void bubble(int s, int e) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < e - 1; j++) {
			if(arr[j]>arr[j+1])
				swap(arr[j], arr[j + 1]);
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
	bubble(0, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}