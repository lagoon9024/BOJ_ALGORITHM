//boj 1012
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int t, n, m, k;
int map[50][50];
bool visit[50][50];

typedef struct pos {
	int r, c;
};


void dfs(int r, int c) {
	visit[r][c] = true;

	int dr[4] = { 0,-1,0,1 };
	int dc[4] = { -1,0,1,0 };
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= m || nc >= n || visit[nr][nc] || map[nr][nc] == 0) continue;
		visit[nr][nc] = true;
		dfs(nr, nc);
	}
}


int main(void) {
	//freopen("test.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;

		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			fill_n(visit[i], n, false);
			fill_n(map[i], n, 0);
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> v >> u;
			map[u][v] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << '\n';
	}
}