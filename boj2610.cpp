// boj 2610 회의준비
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
bool visit[101];
int graph[101][101];
vector<int> members[101];
vector<int> group;
vector<int> ans;

void makegroup(int idx) {
	visit[idx] = true;
	group.push_back(idx);
	for (int i = 0; i < members[idx].size(); ++i) {
		if (visit[members[idx][i]]) continue;
		makegroup(members[idx][i]);
	}
}

void chairman(int idx) {
	for (int k = 0; k < group.size(); ++k) {
		for (int i = 0; i < group.size(); ++i) {
			for (int j = 0; j < group.size(); ++j) {
				if (graph[group[i]][group[j]] > graph[group[i]][group[k]] + graph[group[k]][group[j]])
					graph[group[i]][group[j]] = graph[group[i]][group[k]] + graph[group[k]][group[j]];
			}
		}
	}
	int minimum = INF;
	int pt = idx;
	for (int i = 0; i < group.size(); ++i) {
		int tmpmax = 0;
		for (int j = 0; j <  group.size(); ++j) {
			if (i == j) continue;
			if (graph[group[i]][group[j]] > tmpmax) tmpmax = graph[group[i]][group[j]];
		}
		if (tmpmax < minimum) {
			minimum = tmpmax;
			pt = group[i];
		}
	}
	ans.push_back(pt);
}

int main(void) {
	int n, m;

	cin >> n >> m;

	fill_n(visit, n + 1, false);
	for (int i = 0; i <= n; ++i)
		fill_n(graph[i], n + 1, INF);

	for (int i = 0; i < m; ++i) {
		int cur, next;
		cin >> cur >> next;
		members[cur].push_back(next);
		members[next].push_back(cur);
		graph[cur][next] = graph[next][cur] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		if (visit[i]) continue;
		makegroup(i);
		chairman(i);
		group.clear();
	}

	cout << ans.size() <<'\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';

}