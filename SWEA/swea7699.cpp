// swea 7699 수지의 수지맞는여행
#include <iostream>

using namespace std;
int island[20][20];
int R, C, ans, alphabets;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool cbound(int r, int c) {
	return r >= 0 && c >= 0 && r < R && c < C;
}

void dfs(int r, int c, int x, int depth) {
	if (depth > ans) ans = depth;
	if (ans >= alphabets) return;
	for (int d = 0; d < 4; ++d) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (!cbound(nr, nc) || (x & (1 << island[nr][nc]))) continue;
		dfs(nr, nc, x | 1 << island[nr][nc], depth + 1);
		if (ans >= alphabets) return;
	}
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int x = 0;
		ans = 0;
		cin >> R >> C;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				char c;
				cin >> c;
				island[i][j] = c - 'A';
				x |= 1 << island[i][j];
			}
		}
		alphabets = 0;
		while (x > 0) {
			if (x & 1) ++alphabets;
			x >>= 1;
		}
		dfs(0, 0, 1 << island[0][0], 1);
		cout << '#' << tc << " " << ans << '\n';
	}
}