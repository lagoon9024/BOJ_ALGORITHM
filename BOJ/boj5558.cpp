// boj 5558
#include <iostream>
#include <queue>

using namespace std;

int n, m, k, visit[1000][1000];
char map[1000][1000];
class pos {
public:
	int r, c,move;
	pos(int rr, int cc,int mm) {
		this->r = rr;
		this->c = cc;
		this->move = mm;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<pos> q;
	int sr, sc, eaten;
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push(pos(i, j, 0));
				visit[i][j] = 1;
				eaten = 1;
			}
		}
	}
	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		int curm = q.front().move;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = curr + dr[i];
			int nc = curc + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc] == eaten || map[nr][nc]=='X') continue;
			if (map[nr][nc] - '0' == eaten) {
				if (eaten == k) {
					cout << curm + 1;
					return 0;
				}
				while (!q.empty()) q.pop();
				++eaten;
				visit[nr][nc] = eaten;
				q.push(pos(nr, nc, curm + 1));
				break;
			}
			visit[nr][nc] = eaten;
			q.push(pos(nr, nc, curm + 1));
			
		}
	}
}