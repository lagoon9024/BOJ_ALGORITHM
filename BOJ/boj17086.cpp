// boj 17086 아기상어2
#include <iostream>
#include <queue>

using namespace std;

int map[50][50], d[50][50], n, m;
int dr[] = { -1,-1,-1,1,1,1,0,0 };
int dc[] = { -1,0,1,-1,0,1,-1,1 };

class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
queue<pos> q;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = 1e9;
			cin >> map[i][j];
			if (map[i][j]) {
				q.push(pos(i, j));
				d[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nr = curr + dr[i];
			int nc = curc + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m || map[nr][nc]) continue;
			if (d[nr][nc] != -1 && d[nr][nc] <= d[curr][curc]+1) continue;
			d[nr][nc] = d[curr][curc] + 1;
			q.push(pos(nr, nc));
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[i][j] > ans) ans = d[i][j];
		}
	}
	cout << ans;
}