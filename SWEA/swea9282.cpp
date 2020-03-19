//swea 9282 초콜릿과 건포도
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, map[51][51], d[51][51][51][51];


int dp(int r, int c, int lenr, int lenc) {
	int& ret = d[r][c][lenr][lenc];
	if (lenr == 1 && lenc == 1) return 0;
	if (ret != -1) return ret;
	ret = 1e9;
	int sum = map[r + lenr - 1][c + lenc - 1] - map[r + lenr - 1][c - 1] - map[r - 1][c + lenc - 1] + map[r - 1][c - 1];
	for (int i = 1; i < lenr; ++i) ret = min(ret, sum + dp(r, c, i, lenc) + dp(r + i, c, lenr - i, lenc));
	for (int i = 1; i < lenc; ++i) ret = min(ret, sum + dp(r, c, lenr, i) + dp(r, c + i, lenr, lenc - i));
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		memset(d, -1, sizeof(d));
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 2; j <= m; ++j) {
				map[i][j] += map[i][j - 1];
			}
		}

		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				map[i][j] += map[i - 1][j];
			}
		}
		cout << '#' << tc << " " << dp(1, 1, n, m) << '\n';
	}
}