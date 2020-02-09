// boj 1987 alphabet
#include <iostream>

using namespace std;
int map[22][22];
int n, m;
int alphabet;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int ans = 1;

void go(int r, int c, int d) {
	if (!(alphabet & (1 << map[r + 1][c]))) {
		alphabet |= (1 << map[r + 1][c]);
		go(r + 1, c, d + 1);
		alphabet ^= (1 << map[r + 1][c]);
	}
	if (!(alphabet & (1 << map[r - 1][c]))) {
		alphabet |= (1 << map[r - 1][c]);
		go(r - 1, c, d + 1);
		alphabet ^= (1 << map[r - 1][c]);
	}
	if (!(alphabet & (1 << map[r][c + 1]))) {
		alphabet |= (1 << map[r][c + 1]);
		go(r, c + 1, d + 1);
		alphabet ^= (1 << map[r][c + 1]);
	}
	if (!(alphabet & (1 << map[r][c - 1]))) {
		alphabet |= (1 << map[r][c - 1]);
		go(r, c - 1, d + 1);
		alphabet ^= (1 << map[r][c - 1]);
	}
	if (d > ans) ans = d;
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			map[i][j] = c - 'A' + 1;
		}
	}
	alphabet = 1;
	alphabet |= (1 << map[1][1]);
	go(1, 1, 1);
	cout << ans;
}