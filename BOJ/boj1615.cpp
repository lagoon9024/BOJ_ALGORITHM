//boj 1615 교차개수세기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> joint;
vector<joint> joints;
int map[2001][2001];
int undercnt[2002][2002];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		joints.push_back(joint(u, v));
		map[u][v] = 1;
	}
	for (int i = n; i >= 1; --i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (map[i][j]) ++cnt;
			undercnt[i][j] = undercnt[i + 1][j] + cnt;
		}
	}

	sort(joints.begin(), joints.end());
	long long ans = 0;
	int e, s = 0;
	for (int i = 1; i <= n; ++i) {
		e = lower_bound(joints.begin(), joints.end(), joint(i + 1, 0)) - joints.begin();
		for (int k = s; k < e; ++k) {
			ans += undercnt[i + 1][joints[k].second - 1];
		}
		s = e;
	}
	cout << ans;
}
