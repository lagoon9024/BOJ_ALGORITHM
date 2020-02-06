// boj 1389 케빈베이컨의 6단계 법칙
#include <iostream>

using namespace std;

const int inf = 1e9;
int graph[101][101];
int n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fill_n(graph[i], n + 1, inf);
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int ans, idx;
	ans = inf;

	for (int i = 1; i <= n; ++i) {
		int tmpans = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			tmpans += graph[i][j];
		}
		if (tmpans < ans) {
			ans = tmpans;
			idx = i;
		}
	}

	cout << idx;
}