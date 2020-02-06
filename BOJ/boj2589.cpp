// boj 2589 º¸¹°¼¶
#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;
char map[51][51];
int visit[51][51];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct pos {
	int r, c, dist;
};

bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void search(int r, int c, int pt) {
	queue<pos> q;
	q.push({ r,c,0 });
	visit[r][c] = pt;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		if (tmp.dist > ans) ans = tmp.dist;

		for (int d = 0; d < 4; ++d) {
			int nr = tmp.r + dr[d];
			int nc = tmp.c + dc[d];
			if (visit[nr][nc] == pt || map[nr][nc] == 'W' || !check(nr, nc)) continue;
			visit[nr][nc] = pt;
			q.push({ nr, nc, tmp.dist + 1 });
		}
	}
}

int main(void) {
	ans = 0;
	cin >> n >> m;
	int pt = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'W') continue;
			search(i, j, pt);
			++pt;
		}
	}

	cout << ans;
}