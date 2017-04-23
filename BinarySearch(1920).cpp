#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> arr;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	scanf("%d", &m);
	int num;
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		bool isFound = false;
		int lo = 0;
		int hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] > num) {
				hi = mid;
			}
			else if (arr[mid] < num) {
				lo = mid + 1;
			}
			else {
				printf("1\n");
				isFound = true;
				break;
			}
		}
		if (!isFound)
			printf("0\n");
	}
}