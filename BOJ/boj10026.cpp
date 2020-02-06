// boj 10026 적록색약
#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
bool visit[101][101];
bool weakvisit[101][101];
int n;
int normalreg, reg;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct pos {
	int r, c;
};

bool checkbound(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= n;
}

void weaksearch(int r, int c) {
	queue<pos> q;
	q.push({ r,c });
	weakvisit[r][c] = true;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (weakvisit[nr][nc] || !checkbound(nr, nc)) continue;
			if (map[nr][nc] == 'R' || map[nr][nc] == 'G') {
				weakvisit[nr][nc] = true;
				q.push({ nr,nc });
			}
		}
	}
}

void search(int r, int c, char color) {
	queue<pos> q;
	q.push({ r,c });
	visit[r][c] = true;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (visit[nr][nc] || !checkbound(nr, nc) || map[nr][nc] != color) continue;
			visit[nr][nc] = true;
			q.push({ nr,nc });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == 'B') {
				if (!visit[i][j]) {
					++reg;
					++normalreg;
					search(i, j, 'B');
				}
			}
			else if (map[i][j] == 'R') {
				if (!visit[i][j]) {
					++normalreg;
					search(i, j, 'R');
				}
				if (!weakvisit[i][j]) {
					++reg;
					weaksearch(i, j);
				}
			}
			else if (map[i][j] == 'G') {
				if (!visit[i][j]) {
					++normalreg;
					search(i, j, 'G');
				}
				if (!weakvisit[i][j]) {
					++reg;
					weaksearch(i, j);
				}
			}
		}
	}
	cout << normalreg << " " << reg;
}