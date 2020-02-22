// boj 1473 escape maze
#include <iostream>
#include <queue>

using namespace std;
int n, m;
int map[7][7];
bool visit[7][7][1<<7][1<<7];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
const int inf = 1e9;
int openr[2][4] = { {1,0,1,0},{1,0,0,1} };
int openc[2][4] = { {1,0,0,1},{1,0,1,0} };

class pos {
public:
	int r, c, tr, tc;
	pos(int rr, int cc, int trr, int tcc) {
		this->r = rr;
		this->c = cc;
		this->tr = trr;
		this->tc = tcc;
	}
};

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			map[i][j] = c - 'A';
		}
	}
	queue<pos> q;
	q.push(pos(0, 0, 0, 0));
	visit[0][0][0][0] = true;
	for (int ans = 0; !q.empty(); ++ans) {
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i) {
			pos tmp = q.front();
			q.pop();
			if (tmp.r == n - 1 && tmp.c == m - 1) {
				cout << ans;
				return 0;
			}
			for (int d = 0; d < 4; ++d){
				int turn;
				if (!(tmp.tr & (1 << tmp.r)) == !(tmp.tc & (1 << tmp.c))) turn = 0;
				else turn = 1;

				if (d < 2 && !openr[turn][map[tmp.r][tmp.c]]) continue;
				else if (d >= 2 && !openc[turn][map[tmp.r][tmp.c]]) continue;

				int nr = tmp.r + dr[d];
				int nc = tmp.c + dc[d];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

				if (!(tmp.tr & (1 << nr)) == !(tmp.tc & (1 << nc))) turn = 0;
				else turn = 1;

				if (d < 2 && !openr[turn][map[nr][nc]]) continue;
				else if (d >= 2 && !openc[turn][map[nr][nc]]) continue;

				if (visit[nr][nc][tmp.tr][tmp.tc]) continue;
				visit[nr][nc][tmp.tr][tmp.tc] = true;
				q.push(pos(nr, nc, tmp.tr, tmp.tc));
			}
			int ntr = (tmp.tr & (1 << tmp.r)) ? tmp.tr - (1 << tmp.r) : (tmp.tr | (1 << tmp.r));
			int ntc = (tmp.tc & (1 << tmp.c)) ? tmp.tc - (1 << tmp.c) : (tmp.tc | (1 << tmp.c));
			if (visit[tmp.r][tmp.c][ntr][ntc]) continue;
			visit[tmp.r][tmp.c][ntr][ntc] = true;
			q.push(pos(tmp.r, tmp.c, ntr, ntc));
		}
	}
	cout << -1;
}
