// boj 1937 greedy panda
#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int map[502][502];
int d[502][502];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };

int gopanda(int r, int c) {
	if (d[r][c]>1) return d[r][c];
	
	int ret = d[r][c];
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (map[nr][nc] <= map[r][c]) continue;
		ret=max(ret, d[r][c]+gopanda(nr, nc));
	}
	return d[r][c] = ret;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int res = gopanda(i, j);
			if (res > ans) ans = res;
		}
	}
	cout << ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			d[i][j] = 1;
		}
	}
	solve();
}