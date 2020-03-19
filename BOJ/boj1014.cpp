// boj 1014 да╢в
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
char classroom[10][10];
int except[10];
int caseset[150];
int memo[11][1024];

int cntbit(int num, int idx) {
	if (except[num] & caseset[idx]) return 0;
	int ret = 0;
	int val = caseset[idx];
	while (val > 0) {
		if (val & 1) ++ret;
		val >>= 1;
	}
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	int idx = 0;
	for (int i = 0; i < 1 << 10; ++i) {
		if (!((i << 1) & i)) caseset[idx++] = i;
	}
	caseset[idx] = 1 << 11;
	while (t--) {
		memset(memo, 0, sizeof(memo));
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			except[i] = 2;
			for (int j = 0; j < m; ++j) {
				cin >> classroom[i][j];
				except[i] <<= 1;
				if (classroom[i][j] == 'x') {
					except[i] |= 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; caseset[j] < (1<<m); ++j) {
				for (int k = 0; caseset[k] < (1 << m); ++k) {
					if ((caseset[k] & (caseset[j] << 1)) || (caseset[k] & (caseset[j] >> 1))) continue;
					memo[i][caseset[k]] = max(memo[i][caseset[k]], memo[i - 1][caseset[j]] + cntbit(i - 1, k));
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < idx; ++i) {
			ans = ans < memo[n][caseset[i]] ? memo[n][caseset[i]] : ans;
		}
		cout << ans << '\n';
	}
}