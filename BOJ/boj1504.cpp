// boj 1504 특정한 최단 경로
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e6;
int n, e, pt1, pt2;
int path[3][801];

struct pos {
	int pt, dist;
};


bool compare(pos a, pos b) {
	return a.dist > b.dist;
}

vector<pos> graph[801];

void djikstra(int idx, int pathidx)
{
	vector<pos> v;
	path[pathidx][idx] = 0;
	v.push_back({ idx, 0 });

	while (!v.empty()) {
		pos tmp = v.back();
		v.pop_back();

		if (path[pathidx][tmp.pt] < tmp.dist) continue;
		for (int i = 0; i < graph[tmp.pt].size(); ++i) {
			if (path[pathidx][graph[tmp.pt][i].pt] > path[pathidx][tmp.pt] + graph[tmp.pt][i].dist) {
				path[pathidx][graph[tmp.pt][i].pt] = path[pathidx][tmp.pt] + graph[tmp.pt][i].dist;
				v.push_back({ graph[tmp.pt][i].pt, path[pathidx][graph[tmp.pt][i].pt] });
			}
		}
		sort(v.begin(), v.end(), compare);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> e;

	for (int i = 0; i < 3; ++i)
		fill_n(path[i], n + 1, INF);

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> pt1 >> pt2;

	djikstra(1, 0);
	djikstra(pt1, 1);
	djikstra(pt2, 2);

	int ans = min(path[0][pt1] + path[1][pt2] + path[2][n], path[0][pt2] + path[2][pt1] + path[1][n]);

	if (ans >= INF) cout << -1;
	else cout << ans;
}
