// boj 1916 minimum cost
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int pt, dist;
};

struct cmp {
	bool operator()(pos a, pos b) {
		return a.dist > b.dist;
	}
};

vector<pos> graph[1001];
int djikstra[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, u, v, w, start, end;
	int inf = 1e9;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	cin >> start >> end;

	fill_n(djikstra, n + 1, inf);

	priority_queue<pos, vector<pos>, cmp> pq;

	pq.push({ start,0 });

	while (!pq.empty()) {
		int cur = pq.top().pt;
		int dist = pq.top().dist;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i].pt;
			int nextdist = graph[cur][i].dist + dist;
			if (djikstra[next] <= nextdist)continue;
			djikstra[next] = nextdist;
			pq.push({ next,nextdist });
		}
	}

	cout << djikstra[end];
}