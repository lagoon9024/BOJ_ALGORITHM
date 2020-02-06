// boj 3055 ≈ª√‚
#include <iostream>
#include <queue>
using namespace std;
char map[51][51];
bool visit[51][51];
int dist[51][51];
int r, c;
bool check(int rr, int cc) {
	return rr >= 0 && cc >= 0 && rr < r && cc < c;
}
int main(void) {
	struct pos {
		int r, c;
	};
	queue<pos> q;
	queue<pos> water;
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push({ i,j });
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int size = water.size();
		for(int p=0; p<size; ++p){
			pos tmp = water.front();
			water.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];
				if (visit[nr][nc] || !check(nr, nc) || map[nr][nc] != '.') continue;
				visit[nr][nc] = true;
				water.push({ nr, nc });
			}
		}
		size = q.size();
		for (int p = 0; p < size; ++p) {
			pos tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];
				if (map[nr][nc] == 'D') {
					cout << dist[tmp.r][tmp.c] + 1;
					return 0;
				}
				if (dist[nr][nc] > 0 || visit[nr][nc] || !check(nr, nc) || map[nr][nc] != '.') continue;
				dist[nr][nc] = dist[tmp.r][tmp.c] + 1;
				q.push({ nr, nc });
			}
		}
	}
	cout << "KAKTUS";
}