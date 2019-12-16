// boj 13460 ±∏ΩΩ≈ª√‚2
#include <iostream>

using namespace std;

char map[11][11];
int n, m;
int redr, redc, bluer, bluec;
int ans = 987654321;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };

void move(int rr, int rc, int br, int bc, int depth, int dir) {
	if (depth >= 10) return;
	if (depth >= ans) return;
	bool rflag = false;
	bool bflag = false;
	int nextrr = rr;
	int nextrc = rc;
	int nextbr = br;
	int nextbc = bc;

	while (map[nextrr][nextrc] == '.') {
		nextrr += dr[dir];
		nextrc += dc[dir];
	}
	if (map[nextrr][nextrc] == 'O') rflag = true;
	nextrr -= dr[dir];
	nextrc -= dc[dir];

	while (map[nextbr][nextbc] == '.') {
		nextbr += dr[dir];
		nextbc += dc[dir];
	}
	if (map[nextbr][nextbc] == 'O') bflag = true;
	nextbr -= dr[dir];
	nextbc -= dc[dir];

	if (bflag) return;
	else if (rflag) {
		ans = ans > depth + 1 ? depth + 1 : ans;
		return;
	}
	if (nextrr == rr && nextbr == br && nextrc == rc && nextbc == bc) return;

	if (nextrr == nextbr && nextrc == nextbc) {
		switch (dir) {
		case 0:
			if (rr < br) nextbr += 1;
			else nextrr += 1;
			break;
		case 1:
			if (rc < bc) nextbc += 1;
			else nextrc += 1;
			break;
		case 2:
			if (rr < br) nextrr -= 1;
			else nextbr -= 1;
			break;
		case 3:
			if (rc < bc) nextrc -= 1;
			else nextbc -= 1;
			break;
		}
	}

	for (int i = 0; i < 4; i++)
		move(nextrr, nextrc, nextbr, nextbc, depth + 1, i);

}

void solve() {
	for (int dir = 0; dir < 4; ++dir)
		move(redr, redc, bluer, bluec, 0, dir);
	if (ans == 987654321) cout << -1;
	else cout << ans;
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				redr = i;
				redc = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				bluer = i;
				bluec = j;
				map[i][j] = '.';
			}
		}
	}

	solve();
}