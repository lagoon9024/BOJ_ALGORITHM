// boj 17485 진우의 달 여행(Laaaaaaaaaaaaaaaaaaaaaaarge)
#include <iostream>

using namespace std;

const int INF = 1e9;
int n, m;
int cache[1001][1001][3];
int tmpinput[1001];
int dc[] = { -1,0,1 };

bool check(int c) {
	return c >= 0 && c < m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fill_n(cache[i][j], 3, INF);


	for (int i = 0; i < m; ++i) {
		int val;
		cin >> val;
		for (int j = 0; j < 3; ++j)
			cache[0][i][j] = val;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> tmpinput[j];
		}
		for (int j = 0; j < m; ++j) {
			for (int d = 0; d < 3; ++d) {
				int nr = i - 1;
				int nc = j + dc[d];
				if (!check(nc)) continue;
				for (int prev = 0; prev < 3; ++prev) {
					if (prev == d) continue;
					cache[i][j][d] = cache[i][j][d] > cache[nr][nc][prev] + tmpinput[j] ? cache[nr][nc][prev] + tmpinput[j] : cache[i][j][d];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j)
			ans = cache[n - 1][i][j] < ans ? cache[n - 1][i][j] : ans;
	}

	cout << ans;
}