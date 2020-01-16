// boj17070 move pipe
#include <iostream>

using namespace std;

int N, ans;
int map[18][18];
int dr[] = { 0,1,1 };
int dc[] = { 1,0,1 };
int horiz[] = { 0,2 };
int vertic[] = { 1,2 };

bool check(int r, int c) {
	return r > 0 && c > 0 && r <= N && c <= N;
}


void movepipe(int r, int c, int dir) {
	if (r == N && c == N) {
		++ans;
		return;
	}

	switch (dir) {
	case 0:
		for (int i = 0; i < 2; ++i) {
			int nr = r + dr[horiz[i]];
			int nc = c + dc[horiz[i]];
			if (!check(nr, nc) || map[nr][nc]) continue;
			if (horiz[i] == 2) {
				if (map[nr - 1][nc] || map[nr][nc - 1]) continue;
			}
			movepipe(nr, nc, horiz[i]);
		}
		break;
	case 1:
		for (int i = 0; i < 2; ++i) {
			int nr = r + dr[vertic[i]];
			int nc = c + dc[vertic[i]];
			if (!check(nr, nc) || map[nr][nc]) continue;
			if (vertic[i] == 2) {
				if (map[nr - 1][nc] || map[nr][nc - 1]) continue;
			}
			movepipe(nr, nc, vertic[i]);
		}
		break;
	default:
		for (int i = 0; i < 3; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!check(nr, nc) || map[nr][nc]) continue;
			if (i == 2) {
				if (map[nr - 1][nc] || map[nr][nc - 1]) continue;
			}
			movepipe(nr, nc, i);
		}
		break;
	}
}

int main(void) {
	cin >> N;
	ans = 0;
	for (int i = 0; i < 18; ++i) {
		fill_n(map[i], 18, 1);
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> map[i][j];

	movepipe(1, 2, 0);

	cout << ans;
}