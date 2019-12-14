#include <iostream>

using namespace std;

int N, ans;
int map[20][20];
bool visit[20][20];
bool check[101];
int dr[4] = { -1, 1, 1, -1 };
int dc[4] = { -1, -1, 1, 1 };

void dfs(int r, int c, int cnt, int sr, int sc, int dir) {
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (nr == sr && nc == sc && dir == 3) {
		if (cnt + 1 > ans) ans = cnt + 1;
		return;
	}
	if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc] && !check[map[nr][nc]]) {
		check[map[nr][nc]] = true;
		visit[nr][nc] = true;
		dfs(nr, nc, cnt + 1, sr, sc, dir);
		check[map[nr][nc]] = false;
		visit[nr][nc] = false;
	}
	if (cnt != 0 && dir != 3) {
		nr = r + dr[++dir];
		nc = c + dc[dir];
		if (nr == sr && nc == sc && dir == 3) {
			if (cnt + 1 > ans) ans = cnt + 1;
			return;
		}
		if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc] && !check[map[nr][nc]]) {
			check[map[nr][nc]] = true;
			visit[nr][nc] = true;
			dfs(nr, nc, cnt + 1, sr, sc, dir);
			check[map[nr][nc]] = false;
			visit[nr][nc] = false;
		}
	}
	return;
}

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		ans = -1;
		for (int i = 0; i < N; i++)
			fill_n(visit[i], N, false);
		fill_n(check, 101, false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[map[i][j]] = true;
				visit[i][j] = true;
				dfs(i, j, 0, i, j, 0);
				check[map[i][j]] = false;
				visit[i][j] = false;
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
}