// boj 1956 exercise
#include <iostream>

const int INF = 1e9;
using namespace std;

int graph[401][401];
bool visit[401];
int v, e;

int main(void) {
	cin >> v >> e;
	for (int i = 0; i <= v; ++i)
		fill_n(graph[i],v+1,INF);

	for (int i = 0; i < e; ++i) {
		int r, c, val;
		cin >> r >> c >> val;
		graph[r][c] = val;
	}

	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			for (int k = 1; k <= v; ++k) {
				if (graph[j][i] + graph[i][k] < graph[j][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; ++i) {
		if (graph[i][i] < ans)
		ans = graph[i][i];
	}
	if (ans >= INF) cout << -1;
	else cout << ans;
}