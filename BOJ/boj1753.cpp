// boj 1753 minimum path
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;

struct graph {
	int pt, dist;
};
vector<graph> map[20001];
int djikstra[20001];
bool visit[20001];

struct cmp {
	bool operator()(graph a, graph b) {
		return a.dist > b.dist;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 1; i <= V; ++i) djikstra[i] = inf;

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u].push_back({ v,w });
	}

	priority_queue<graph, vector<graph>, cmp> pq;

	pq.push({ K,0 });
	while (!pq.empty()) {
		int cur = pq.top().pt;
		int dist = pq.top().dist;
		pq.pop();
		visit[cur] = true;
		for (int i = 0; i < map[cur].size(); ++i) {
			int nextdist = dist + map[cur][i].dist;
			int next = map[cur][i].pt;
			if (visit[next] || nextdist >= djikstra[next] ) continue;
			djikstra[next] = nextdist;
			pq.push({ next,nextdist });
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (i == K) cout << 0 << '\n';
		else if (djikstra[i] == inf)
			cout << "INF\n";
		else
			cout << djikstra[i] << '\n';
	}
}