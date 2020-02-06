// boj 6087 레이저통신
#include <iostream>
#include <queue>
using namespace std;
char map[101][101];
int n, m;
class pos {
public:
	int r, c, dir, ccnt;
	pos() {
		r = c = dir = ccnt = -1;
	}
	pos(int rr, int cc, int dir, int ccnt) {
		this->r = rr;
		this->c = cc;
		this->dir = dir;
		this->ccnt = ccnt;
	}
};
pos LASER[2];
int visit[101][101];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		fill_n(visit[i], m, -1);
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				LASER[idx++] = pos(i, j, 0, 0);
			}
		}
	}
	queue<pos> q;
	for (int i = 0; i < 4; ++i) {
		LASER[0].dir = i;
		q.push(LASER[0]);
	}
	visit[LASER[0].r][LASER[0].c] = 0;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ncnt;
			if (dr[tmp.dir] * (-1) == dr[i] && dc[tmp.dir] * (-1) == dc[i]) continue;
			else if (dr[tmp.dir] == dr[i] && dc[tmp.dir] == dc[i]) ncnt = tmp.ccnt;
			else ncnt = tmp.ccnt + 1;
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || map[nr][nc] == '*') continue;
			if (visit[nr][nc] != -1 && visit[nr][nc] < ncnt) continue;
			visit[nr][nc] = ncnt;
			if (nr == LASER[1].r && nc == LASER[1].c) continue;
			q.push(pos(nr, nc, i, ncnt));
		}
	}
	cout << visit[LASER[1].r][LASER[1].c];
}