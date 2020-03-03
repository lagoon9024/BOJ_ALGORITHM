//boj 2132 나무 위의 벌레
/* 미친듯이 틀린이유 
1: 각 node가 시작점이 될 수 있음을 간과. 
->더 이상 진행 불가한 node기준으로만 문제 풀이한 부분 
(EX : 0의 weight를 가진 노드가 3이고, 2의 weight를 가진 node가 2의 값을 가지면, 2를 단말로 설정해야하나 3을 단말로 설정한 문제)
2: queue가 터짐 -> 각 노드가 0의 weight를 가질 수 있음에, 0을 초기값으로 잡아 queue가 터져버림
초기값 -1로 변환 후 갱신하여 해결
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int node[10001], weighted[10001], N, maxw, minpt;
vector<int> edges[10001];
vector<int> searchpt;

void findedge(int cur, int weight, int spt) {
	fill_n(weighted, N + 1, -1);
	queue<int> q;
	q.push(cur);
	weighted[cur] = weight;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (maxw < weighted[now]) {
			maxw = weighted[now];
			minpt = now > spt ? spt : now;
		}
		else if (maxw == weighted[now]) {
			minpt = minpt < now ? minpt : (now > spt ? spt : now);
		}

		for (int i = 0; i < edges[now].size(); ++i) {
			if (weighted[edges[now][i]] == -1) {
				weighted[edges[now][i]] = weighted[now] + node[edges[now][i]];
				q.push(edges[now][i]);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> node[i];
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	maxw = 0; minpt = 1e9;
	findedge(1, node[1], 1);
	for (int i = 1; i <= N; ++i) {
		if (weighted[i] == maxw) {
			searchpt.push_back(i);
		}
	}
	maxw = 0; minpt = 1e9;
	for (int i = 0; i < searchpt.size(); ++i) {
		findedge(searchpt[i], node[searchpt[i]], searchpt[i]);
	}
	cout << maxw << " " << minpt;
}