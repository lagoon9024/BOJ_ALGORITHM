// boj 15906 변신 이동 게임
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
char map[501][501];
int N, T, R, C;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
int dist[2][500][500];

class pos {
public:
	int r, c, m, w;
	pos(int rr, int cc, int mm, int ww) {
		this->r = rr;
		this->c = cc;
		this->m = mm;
		this->w = ww;
	}
};

bool operator<(pos a, pos b) {
	return a.w > b.w;
}

int findwarp(int r, int c, int d) {
	int ret;
	switch (d) {
	case 0:
		ret = r;
		while (ret > 0) {
			--ret;
			if (map[ret][c] == '#') return ret;
		}
		return -1;
	case 1:
		ret = r;
		while (ret < N - 1) {
			++ret;
			if (map[ret][c] == '#') return ret;
		}
		return -1;
	case 2:
		ret = c;
		while (ret > 0) {
			--ret;
			if (map[r][ret] == '#') return ret;
		}
		return -1;
	case 3:
		ret = c;
		while (ret < N - 1) {
			++ret;
			if (map[r][ret] == '#') return ret;
		}
		return -1;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> T >> R >> C;
	//N = R = C = 500;
	//T = 0;
	R--; C--;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dist[0][i][j] = dist[1][i][j] = 1e9;
			cin >> map[i][j];
			//map[i][j] = '#';
		}
	}
	priority_queue<pos> v;
	v.push(pos(0, 0, 0, 0));
	dist[0][0][0] = 0;
	while (!v.empty()) {
		pos cur = v.top();
		v.pop();
		if (cur.r == R && cur.c == C) {
			cout << min(dist[0][R][C], dist[1][R][C]);
			return 0;
		}
		if (dist[cur.m][cur.r][cur.c] < cur.w) continue;
		for (int i = 0; i < 4; ++i) {
			int nr = cur.r, nc = cur.c;
			if (cur.m) {
				if (i < 2) nr = findwarp(nr, nc, i);
				else nc = findwarp(nr, nc, i);
			}
			else {
				nr += dr[i];
				nc += dc[i];
			}
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (dist[cur.m][nr][nc] > dist[cur.m][cur.r][cur.c] + 1) {
				dist[cur.m][nr][nc] = dist[cur.m][cur.r][cur.c] + 1;
				if (nr == R && nc == C) {
					cout << min(dist[0][R][C], dist[1][R][C]);
					return 0;
				}
				v.push(pos(nr, nc, cur.m, dist[cur.m][nr][nc]));
			}
		}
		int nm = !cur.m;
		if (cur.m) {
			if (dist[nm][cur.r][cur.c] > dist[cur.m][cur.r][cur.c]) {
				dist[nm][cur.r][cur.c] = dist[cur.m][cur.r][cur.c];
				v.push(pos(cur.r, cur.c, nm, dist[nm][cur.r][cur.c]));
			}
		}
		else {
			if (dist[nm][cur.r][cur.c] > dist[cur.m][cur.r][cur.c] + T) {
				dist[nm][cur.r][cur.c] = dist[cur.m][cur.r][cur.c] + T;
				v.push(pos(cur.r, cur.c, nm, dist[nm][cur.r][cur.c]));
			}
		}
	}
}