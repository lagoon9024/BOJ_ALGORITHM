//boj 1726 ·Îº¿
#include <iostream>
#include <queue>

using namespace std;
int n, m, map[101][101];
int dirvisit[5][101][101];
int dc[] = { 0,1,-1,0,0 };
int dr[] = { 0,0,0,1,-1 };

class robot {
public:
	int r, c, d, cmd;
	robot(int rr, int cc, int dd) {
		this->r = rr;
		this->c = cc;
		this->d = dd;
	}
};

bool cbound(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

int turnleft(int d) {
	if (d == 1) return 4;
	else if (d == 2) return 3;
	else if (d == 3) return 1;
	else return 2;
}
int turnright(int d) {
	if (d == 1) return 3;
	else if (d == 2) return 4;
	else if (d == 3) return 2;
	else return 1;
}


int main(void) {
	cin >> n >> m;
	int ans = 1e9;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			for(int k=1;k<=4;++k) dirvisit[k][i][j] = 1e9;
		}
	}
	int sr, sc, sd, er, ec, ed;
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	if (sr == er && sc == ec && sd == ed) {
		cout << 0;
		return 0;
	}
	queue<robot> q;
	q.push(robot(sr, sc, sd));
	dirvisit[sd][sr][sc] = 0;

	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		int curd = q.front().d;
		q.pop();

		int cmdcnt = dirvisit[curd][curr][curc] + 1;
		for (int i = 0; i < 2; ++i) {
			int nd;
			if (i) nd = turnleft(curd);
			else nd = turnright(curd);
			if (curr == er && curc == ec && nd == ed) {
				if (ans > cmdcnt)ans = cmdcnt;
				break;
			}
			if (dirvisit[nd][curr][curc]<=cmdcnt) continue;
			dirvisit[nd][curr][curc] = cmdcnt;
			q.push(robot(curr, curc, nd));
		}
		for (int mv = 1; mv <= 3; ++mv) {
			int nr = curr + dr[curd] * mv;
			int nc = curc + dc[curd] * mv;
			if (nr == er && nc == ec && curd == ed) {
				if (ans > cmdcnt) ans = cmdcnt;
				break;
			}
			if (!cbound(nr, nc) || map[nr][nc]) break;
			if (dirvisit[curd][nr][nc] <= cmdcnt)continue;
			dirvisit[curd][nr][nc] = cmdcnt;
			q.push(robot(nr, nc, curd));
		}
	}
	cout << ans;
}