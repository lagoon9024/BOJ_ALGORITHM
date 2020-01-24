// boj 18223 민준이와 마산 그리고 건우
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int v, e, p;
int djikstra[5001];

struct pos {
	int next, dist;
};

vector<pos> adj[5001];

void djiks(int now) {
	fill_n(djikstra, v + 1, INF);
	queue<int> djik;
	djik.push(now);
	djikstra[now] = 0;

	while (!djik.empty()) {
		int cur = djik.front();
		djik.pop();
		for (int i =1; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].next;
			int dist = adj[cur][i].dist;
			if (djikstra[next] > djikstra[cur] + dist) {
				djikstra[next] = djikstra[cur] + dist;
				djik.push(next);
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> v >> e >> p;
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int starttoV, starttoP, ptov;
	djiks(1);
	starttoV = djikstra[v];
	starttoP = djikstra[p];
	djiks(p);
	ptov = djikstra[v];

	bool flag = false;

	if (starttoV == starttoP + ptov) flag = true;

	if (flag) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}