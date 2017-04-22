#include <iostream>
#include <algorithm>
using namespace std;
int capacity, n,order;
int heap[100001];

void upheap(int x) {
	heap[++capacity] = x;
	int pos = capacity;
	while (pos != 1) {
		if (heap[pos] >= heap[pos / 2])
			break;
		swap(heap[pos], heap[pos / 2]);
		pos = pos / 2;
	}
}

void downheap() {
	heap[1] = heap[capacity];
	int pos = 1;
	capacity--;
	while (heap[pos] > heap[pos * 2] || heap[pos] > heap[pos * 2 + 1]) {
		if (pos * 2 + 1 <= capacity && heap[pos * 2 + 1] < heap[pos * 2]) {
			swap(heap[pos], heap[pos * 2 + 1]);
			pos = pos * 2 + 1;
		}
		else if (pos * 2 <= capacity && heap[pos * 2] < heap[pos]) {
			swap(heap[pos], heap[pos * 2]);
			pos = pos * 2;
		}
		else break;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &order);
		if (order == 0) {
			if (capacity == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", heap[1]);
				downheap();
			}
		}
		else {
			upheap(order);
		}
	}
}