// boj 1967 트리의 지름
#include <iostream>
#include <vector>

using namespace std;
class pos {
public:
	int next, dist;
	pos(int n, int d) {
		this->next = n;
		this->dist = d;
	}
};
vector<pos> trees[10001];
int maxd, pt, dist[10001];
void findnode(int n, int weight) {
	dist[n] = weight;

	if (weight > maxd) {
		maxd = weight;
		pt = n;
	}

	for (int i = 0; i < trees[n].size(); ++i) {
		if (!dist[trees[n][i].next]) {
			findnode(trees[n][i].next, weight + trees[n][i].dist);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		trees[u].push_back(pos(v, d));
		trees[v].push_back(pos(u, d));
	}
	findnode(1, 0);
	fill_n(dist, n + 1, 0);
	findnode(pt, 0);

	cout << maxd;
}