// boj 1707
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[20001];
int v, e;
int visit[20001];
bool check[20001];

bool bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visit[cur] = 1;
	
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		int nextcolor = visit[tmp]==2?1:2;
		for (int i = 0; i < graph[tmp].size(); i++) {
			if (visit[graph[tmp][i]] == visit[tmp]) return false;
			else if (visit[graph[tmp][i]] == nextcolor) continue;
			if(visit[graph[tmp][i]]==0){
				visit[graph[tmp][i]] = nextcolor;
				q.push(graph[tmp][i]);
			}
		}
	}
	return true;
}

bool isbinarygraph() {
	fill_n(visit, v + 1, 0);
	fill_n(check, v + 1, false);
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (visit[i]==0) {
			if (!bfs(i)) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		int cur, next;
		for (int j = 0; j < e; j++) {
			cin >> cur >> next;
			graph[cur].push_back(next);
			graph[next].push_back(cur);
		}

		if (isbinarygraph()) cout << "YES\n";
		else cout << "NO\n";

		for (int j = 1; j <= v; j++)
			graph[j].clear();
	}
}