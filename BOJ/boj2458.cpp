// boj 2458 Å°¼ø¼­
#include <iostream>

using namespace std;

const int inf = 1e9;
int graph[501][501];
int connected[501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		fill_n(graph[i], n + 1, inf);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (graph[i][j] <= graph[i][k] + graph[k][j]) continue;
				graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] == inf) continue;
			++connected[i]; ++connected[j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (connected[i] == n - 1) ++ans;

	cout << ans;
}