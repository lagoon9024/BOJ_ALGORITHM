// boj 14939 불끄기
#include <iostream>
#include <string>
using namespace std;
int map[10][10];
int cmap[10][10];


void change(int r, int c) {
	cmap[r][c] ^= 1;
	if (r) cmap[r - 1][c] ^= 1;
	if (c) cmap[r][c-1] ^= 1;
	if (r < 9) cmap[r + 1][c] ^= 1;
	if (c < 9) cmap[r][c + 1] ^= 1;
}

int main(void) {
	string s;
	for (int i = 0; i < 10; ++i) {
		cin >> s;
		for (int j = 0; j < 10; ++j) {
			if (s[j] == 'O') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	int ans = 1e9;
	// 첫줄의 상태에 따라 아랫줄의 상태가 결정
	// 따라서 첫줄은 모든 경우의 수를 진행
	for (int i = (1 << 10) - 1; i >=0 ; --i) {
		int ret = 0;
		for (int r = 0; r < 10; ++r)
			for (int c = 0; c < 10; ++c)
				cmap[r][c] = map[r][c];

		for (int col = 0; col < 10; ++col) {
			if (i & (1 << col)) {
				change(0, col);
				++ret;
			}
		}
		for (int row = 1; row < 10; ++row) {
			for (int col = 0; col < 10; ++col) {
				if (cmap[row - 1][col]) {
					change(row, col);
					++ret;
				}
			}
		}
		bool alloff = true;
		for (int col = 0; col < 10; ++col) {
			if (cmap[9][col]) {
				alloff = false;
				break;
			}
		}
		if (alloff) ans = ans > ret ? ret : ans;
	}
	ans = ans == 1e9 ? -1 : ans;
	cout << ans;
}