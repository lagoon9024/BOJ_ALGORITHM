//boj 14927 전구끄기
#include <iostream>
using namespace std;
int map[18][18], cmap[18][18], n;

void change(int r, int c) {
	cmap[r][c] ^= 1;
	if (r) cmap[r - 1][c] ^= 1;
	if (c) cmap[r][c - 1] ^= 1;
	if (r < n-1) cmap[r + 1][c] ^= 1;
	if (c < n-1) cmap[r][c + 1] ^= 1;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	int ans = 1e9;
	// 첫줄의 상태에 따라 아랫줄의 상태가 결정
	// 따라서 첫줄은 모든 경우의 수를 진행
	for (int i = (1 << n) - 1; i >= 0; --i) {
		int ret = 0;
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				cmap[r][c] = map[r][c];

		for (int col = 0; col < n; ++col) {
			if (i & (1 << col)) {
				change(0, col);
				++ret;
			}
		}
		for (int row = 1; row < n; ++row) {
			for (int col = 0; col < n; ++col) {
				if (cmap[row - 1][col]) {
					change(row, col);
					++ret;
				}
			}
		}
		bool alloff = true;
		for (int col = 0; col < n; ++col) {
			if (cmap[n-1][col]) {
				alloff = false;
				break;
			}
		}
		if (alloff) ans = ans > ret ? ret : ans;
	}
	ans = ans == 1e9 ? -1 : ans;
	cout << ans;
}