//boj 2132 ���� ���� ����
/* ��ģ���� Ʋ������ 
1: �� node�� �������� �� �� ������ ����. 
->�� �̻� ���� �Ұ��� node�������θ� ���� Ǯ���� �κ� 
(EX : 0�� weight�� ���� ��尡 3�̰�, 2�� weight�� ���� node�� 2�� ���� ������, 2�� �ܸ��� �����ؾ��ϳ� 3�� �ܸ��� ������ ����)
2: queue�� ���� -> �� ��尡 0�� weight�� ���� �� ������, 0�� �ʱⰪ���� ��� queue�� ��������
�ʱⰪ -1�� ��ȯ �� �����Ͽ� �ذ�
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