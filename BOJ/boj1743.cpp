// boj 1743 음식물 피하기
#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visit[101][101];

struct pos {
	int r, c;
};

int main(void) {
	int n, m, k, r, c;
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i) {
		cin >> r >> c;
		map[r][c] = 1;
	}

	queue<pos> q;
	int ans = 0;
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] && !visit[i][j]) {
				int tsize = 1;
				q.push({ i,j });
				visit[i][j] = true;

				while (!q.empty()) {
					pos tmp = q.front();
					q.pop();

					for (int d = 0; d < 4; ++d) {
						int nr = tmp.r + dr[d];
						int nc = tmp.c + dc[d];

						if (nr < 1 || nc < 1 || nr > n || nc > m || visit[nr][nc] || !map[nr][nc])continue;
						visit[nr][nc] = true;
						q.push({ nr,nc });
						++tsize;
					}
				}
				if (tsize > ans) ans = tsize;
			}
		}
	}
	cout << ans;
}