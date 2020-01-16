// boj 1719 ец╧Х
#include <iostream>

using namespace std;

int n, m;
const int INF = 1e9;
int map[201][201];
int prevpt[201][201];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		fill_n(map[i], n + 1, INF);

	for (int i = 0; i < m; ++i) {
		int cur, next, val;
		cin >> cur >> next >> val;
		map[cur][next] = val;
		map[next][cur] = val;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			prevpt[i][j] = j;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
					prevpt[i][j] = prevpt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) cout << "- ";
			else cout << prevpt[i][j] << " ";
		}
		cout << '\n';
	}
}