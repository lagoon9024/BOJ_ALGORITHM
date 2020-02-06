// boj 14499 주사위굴리기
#include <iostream>

using namespace std;

int map[20][20];
int dice[] = { 0,0,0,0,0,0 };
int diceidx[] = { 0,1,2,3,4,5 };//top bottom left rigth up down
int n, m, x, y, k;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void go(int x, int y, int command) {
	int tmp;
	switch(command) {
		case 1:
			tmp = diceidx[3];
			diceidx[3] = diceidx[0];
			diceidx[0] = diceidx[2];
			diceidx[2] = diceidx[1];
			diceidx[1] = tmp;
			break;
		case 2:
			tmp = diceidx[3];
			diceidx[3] = diceidx[1];
			diceidx[1] = diceidx[2];
			diceidx[2] = diceidx[0];
			diceidx[0] = tmp;
			break;
		case 3:
			tmp = diceidx[4];
			diceidx[4] = diceidx[0];
			diceidx[0] = diceidx[5];
			diceidx[5] = diceidx[1];
			diceidx[1] = tmp;
			break;
		case 4:
			tmp = diceidx[4];
			diceidx[4] = diceidx[1];
			diceidx[1] = diceidx[5];
			diceidx[5] = diceidx[0];
			diceidx[0] = tmp;
			break;
	}
	if (map[x][y]>0) {
		dice[diceidx[1]] = map[x][y];
		map[x][y] = 0;
	}
	else {
		map[x][y] = dice[diceidx[1]];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	int prevx = x;
	int prevy = y;

	for (int i = 0; i < k; ++i) {
		int command;
		cin >> command;
		int nx = prevx + dr[command - 1];
		int ny = prevy + dc[command - 1];
		if (!check(nx, ny)) continue;
		go(nx, ny, command);
		cout << dice[diceidx[0]] << '\n';
		prevx = nx;
		prevy = ny;
	}
}