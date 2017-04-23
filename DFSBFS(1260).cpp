#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n, m, s, u, v;
vector < vector < int > > arr;
bool visited[1001];

void dfs(int s)
{
	printf("%d ", s);
	visited[s] = true;
	for (int i = 0; i < arr[s].size(); i++)
	{
		if (!visited[arr[s][i]])
			dfs(arr[s][i]);
	}
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		visited[tmp] = true;
		for (int i = 0; i < arr[tmp].size(); i++)
		{
			if (!visited[arr[tmp][i]])
			{
				visited[arr[tmp][i]] = true;
				q.push(arr[tmp][i]);
			}
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &s);
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end());
	dfs(s);
	cout << endl;
	memset(visited, false, sizeof(visited));
	bfs(s);
	cout << endl;
}