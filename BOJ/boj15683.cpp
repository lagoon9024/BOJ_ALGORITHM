#include <iostream>
#include <vector>

using namespace std;

int row, col, ans;
int office[8][8];
int map[8][8];

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };

struct pos {
	int r, c, type;
};

vector<pos> cctv;

void calc(vector<int> dirset) {
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = office[i][j];

	int d, nr, nc, nd;
	for (int i = 0; i < cctv.size(); i++) {
		d = dirset[i];
		switch (cctv[i].type) {
		case 1:
			nr = cctv[i].r + dr[d];
			nc = cctv[i].c + dc[d];
			while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
				if (office[nr][nc] == 0) map[nr][nc] = -1;
				nr += dr[d];
				nc += dc[d];
			}
			break;
		case 2:
			nr = cctv[i].r + dr[d];
			nc = cctv[i].c + dc[d];
			while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
				if (office[nr][nc] == 0) map[nr][nc] = -1;
				nr += dr[d];
				nc += dc[d];
			}
			nr = cctv[i].r - dr[d];
			nc = cctv[i].c - dc[d];
			while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
				if (office[nr][nc] == 0) map[nr][nc] = -1;
				nr -= dr[d];
				nc -= dc[d];
			}
			break;
		case 3:
			nr = cctv[i].r + dr[d];
			nc = cctv[i].c + dc[d];
			while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
				if (office[nr][nc] == 0) map[nr][nc] = -1;
				nr += dr[d];
				nc += dc[d];
			}
			nd = d + 1;
			if (nd == 4) nd = 0;
			nr = cctv[i].r + dr[nd];
			nc = cctv[i].c + dc[nd];
			while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
				if (office[nr][nc] == 0) map[nr][nc] = -1;
				nr += dr[nd];
				nc += dc[nd];
			}
			break;
		case 4:
			for (int j = 0; j < 4; j++) {
				if (d == j) continue;
				nr = cctv[i].r + dr[j];
				nc = cctv[i].c + dc[j];
				while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
					if (office[nr][nc] == 0) map[nr][nc] = -1;
					nr += dr[j];
					nc += dc[j];
				}
			}
			break;
		case 5:
			for (int j = 0; j < 4; j++) {
				nr = cctv[i].r + dr[j];
				nc = cctv[i].c + dc[j];
				while (office[nr][nc] != 6 && nr >= 0 && nc >= 0 && nr < row && nc < col) {
					if (office[nr][nc] == 0) map[nr][nc] = -1;
					nr += dr[j];
					nc += dc[j];
				}
			}
			break;
		}
	}
	//cout << "SIZEOF DIRSET : " << dirset.size() << '\n';
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (map[i][j] == 0) cnt++;
	if (cnt < ans) ans = cnt;
	//dirset.clear();
}

void observe(int depth, vector<int> dirset) {
	if (depth >= cctv.size()) {
		calc(dirset);
		return;
	}
	for (int d = 0; d < 4; d++) {
		dirset.push_back(d);
		observe(depth + 1, dirset);
		dirset.pop_back();
	}
}

void solve() {
	vector<int> dirset;
	dirset.clear();
	for (int d = 0; d < 4; d++) {
		dirset.push_back(d);
		observe(1, dirset);
		dirset.pop_back();
	}
	cout << ans;
}

int main(void) {
	ans = 987654321;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6) {
				cctv.push_back({ i, j, office[i][j] });
			}
		}
	}

	//cout << "CCTV : " << cctv.size();
	solve();
}