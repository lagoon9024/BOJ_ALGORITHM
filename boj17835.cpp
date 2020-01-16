// boj 17835 면접보는 승범이네
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e10;
int n, m, k;

struct pos {
	int next, dist;
};

vector<pos> graph[100001];
queue<int> interview;
long long distmap[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	fill_n(distmap, n + 1, INF);

	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[v].push_back({ u,c });
	}
	
	for (int i = 0; i < k; ++i) {
		int place;
		cin >> place;
		interview.push(place);
		distmap[place] = 0;
	}

	int anspt=0;
	long long ansdist=0;
	
	while (!interview.empty()) {
		int now = interview.front();
		interview.pop();

		for (int i = 0; i < graph[now].size(); ++i) {
			int nextpt = graph[now][i].next;
			int dist = graph[now][i].dist;

			if (distmap[now] + dist < distmap[nextpt]) {
				distmap[nextpt] = distmap[now] + dist;
				interview.push(nextpt);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (distmap[i] > ansdist) {
			ansdist = distmap[i];
			anspt = i;
		}
	}
	
	cout << anspt << '\n' << ansdist;
}