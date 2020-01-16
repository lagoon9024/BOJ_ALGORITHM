// boj 14621 나만 안되는 연애
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int univ[1001];
int set[1001];
int n, m;

struct pos {
	int cur, next, dist;
};
vector<pos> roads;

int find(int u) {
	if (u == set[u]) return u;
	return set[u] = find(set[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;
	set[u] = v;
	return true;
}

bool compare(pos a, pos b) {
	return a.dist > b.dist;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		set[i] = i;
		if (ch == 'M') univ[i] = 1;
		else univ[i] = 2;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		roads.push_back({ u,v,d });
	}

	sort(roads.begin(), roads.end(), compare);

	int ans = 0;
	while (!roads.empty()) {
		pos tmp = roads.back();
		roads.pop_back();

		if (univ[tmp.cur] != univ[tmp.next] && merge(tmp.cur, tmp.next))
			ans += tmp.dist;
	}

	for (int i = 1; i < n; ++i) {
		if (merge(i,i+1)) {
			cout << -1;
			return 0;
		}
	}

	cout << ans;
}