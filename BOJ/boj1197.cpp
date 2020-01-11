// boj 1197 minimum spanning tree
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct graph {
	int now, target, weight;
};

struct cmp {
	bool operator()(graph a, graph b) {
		return a.weight > b.weight;
	}
};

int v, e;

int getparent(int set[], int x) {
	if (set[x] == x)return x;
	return set[x] = getparent(set, set[x]);
}


void Union(int set[], int x, int y) {
	x = getparent(set, x);
	y = getparent(set, y);

	if (x < y) set[y] = x;
	else set[x] = y;
}

bool find(int set[], int x, int y) {
	x = getparent(set, x);
	y = getparent(set, y);
	if (x == y) return true;
	return false;
}

int main(void) {
	cin >> v >> e;
	priority_queue<graph, vector<graph>, cmp> pq;
	int set[10001];
	for (int i = 1; i <= v; ++i)
		set[i] = i;
	for (int i = 0; i < e; ++i) {
		int v1, v2, wei;

		cin >> v1 >> v2 >> wei;
		pq.push({ v1,v2,wei });
	}
	int ans = 0;
	while (!pq.empty()){
		graph tmp = pq.top();
		pq.pop();
		if (!find(set, tmp.now, tmp.target)) {
			ans += tmp.weight;
			Union(set, tmp.now, tmp.target);
		}
	}

	cout << ans;
}