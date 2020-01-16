// boj 11404 floyd
#include <iostream>

using namespace std;
const int INF = 1e9;
int n, m;
int dgraph[101][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		fill_n(dgraph[i], n + 1, INF);

	for (int i = 0; i < m; ++i) {
		int cur, goal, val;
		cin >> cur >> goal >> val;
		if (dgraph[cur][goal] > val)
			dgraph[cur][goal] = val;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dgraph[i][k] + dgraph[k][j] < dgraph[i][j])
					dgraph[i][j] = dgraph[i][k] + dgraph[k][j];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dgraph[i][j] == INF || i==j) cout << 0 << " ";
			else cout << dgraph[i][j] << " ";
		}
		cout << '\n';
	}
}