// boj 4179 บา!
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class pos {
public:
	int r, c, f;
	pos(int rr, int cc, int ff) {
		this->r = rr;
		this->c = cc;
		this->f = ff;
	}
};

char map[1001][1001];
int r, c, sx, sy;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<pos> q;
int dist[1001][1001];

bool check(int rr, int cc) {
	return rr >= 0 && cc >= 0 && rr < r && cc < c;
}

int main(void) {
	//ifstream cin("text.txt");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				sx = i, sy = j;
			}
			else if (map[i][j] == 'F') {
				q.push(pos(i, j, 1));
				dist[i][j] = 1;
			}
		}
	}

	q.push(pos(sx, sy, 0));
	dist[sx][sy] = 1;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			if (!check(nr, nc)) {
				if (tmp.f) continue;
				cout << dist[tmp.r][tmp.c];
				return 0;
			}
			if (dist[nr][nc] || map[nr][nc] == '#') continue;
			q.push(pos(nr, nc, tmp.f));
			dist[nr][nc] = dist[tmp.r][tmp.c] + 1;
			
		}
	}
	cout << "IMPOSSIBLE";
}