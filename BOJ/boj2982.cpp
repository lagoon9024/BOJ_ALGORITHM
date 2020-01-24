// boj 2982 ±πø’¿« πÊπÆ
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, m, a, b, k, g;
int graph[1001][1001];
int godu[1001][1001];
int visit[1001];
int Move[1001];
int isvisit[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fill_n(godu[i], n + 1, INF);
		fill_n(graph[i], n + 1, INF);
	}
	cin >> a >> b >> k >> g;
	for (int i = 0; i < g; ++i) {
		cin >> visit[i];
		visit[i];
	}
	for (int i = 0; i < m; ++i) {
		int u, v, l;
		cin >> u >> v >> l;
		graph[u][v] = graph[v][u] = l;
	}

	for (int i = 1, t=0; i < g; ++i) {
		godu[visit[i - 1]][visit[i]] = godu[visit[i]][visit[i-1]] = t;
		t += graph[visit[i - 1]][visit[i]];
	}

	for (int i = 1; i <= n; ++i) {
		Move[i] = INF;
		isvisit[i] = 0;
	}
	Move[a] = k;

	for (int i = 1; i <= n; ++i) {
		int idx = -1;
		for (int j = 1; j <= n; ++j) {
			if (isvisit[j]) continue;
			if (idx == -1 || Move[j] < Move[idx]) idx = j;
		}
		isvisit[idx] = 1;

		for (int j = 1; j <= n; ++j) {
			if (Move[idx] < godu[idx][j])
				Move[j] = min(Move[j], Move[idx]+graph[idx][j]);
			else
				Move[j] = min(Move[j], max(Move[idx], graph[idx][j] + godu[idx][j])+graph[idx][j]);
		}
	}

	cout << Move[b] - Move[a];
}