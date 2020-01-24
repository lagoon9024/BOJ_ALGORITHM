// boj 4991 cleaner robot
#include <iostream>
#include <queue>

using namespace std;

char room[22][22];
int visit[22][22];
int dust[11][11];
int cache[11][1 << 11];
int w, h, robotr, robotc, dustcnt;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct pos {
	int r, c, dist;
};

pos dustpos[10];

int _min(int a, int b) {
	if (a > b) return b;
	return a;
}

bool checkboundary(int r, int c) {
	return r >= 1 && c >= 1 && r <= h && c <= w;
}

void bfs(pos dustpt, int idx) {
	queue<pos> q;
	q.push({ dustpt.r, dustpt.c ,0 });
	for (int i = 1; i <= h; ++i)
		fill_n(visit[i], w + 1, -1);
	visit[dustpt.r][dustpt.c] = 0;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			int ndist = tmp.dist + 1;
			if (!checkboundary(nr, nc) || room[nr][nc] == 'x') continue;
			if (visit[nr][nc] != -1) continue;
			visit[nr][nc] = ndist;
			q.push({ nr,nc,ndist });
		}
	}
	for (int i = 0; i < dustcnt; ++i) {
		dust[idx][i] = visit[dustpos[i].r][dustpos[i].c];
	}
}

int dp(int dustnum, int msk) {
	if (msk + 1 == (1 << dustcnt)) return 0;
	int& ref = cache[dustnum][msk];
	if (ref != -1) return ref;
	ref = 1e9;
	for (int i = 0; i < dustcnt; ++i) {
		if (msk & (1 << i)) continue;
		ref = _min(ref, dp(i, msk | (1 << i)) + dust[dustnum][i]);
	}
	return ref;
}

int solve() {
	for (int i = 0; i < dustcnt; ++i) {
		if (dust[0][i] == -1) return -1;
	}
	return dp(0, 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (1) {
		cin >> w >> h;
		dustcnt = 1;
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> room[i][j];
				if (room[i][j] == 'o') {
					dustpos[0].r = i;
					dustpos[0].c = j;
				}
				else if (room[i][j] == '*') {
					dustpos[dustcnt].r = i;
					dustpos[dustcnt].c = j;
					++dustcnt;
				}
			}
		}

		for (int i = 0; i < dustcnt; ++i)
			fill_n(cache[i], 1 << dustcnt, -1);
		for (int i = 0; i < dustcnt; ++i)
			bfs(dustpos[i], i);
		cout << solve() << '\n';
	}
}