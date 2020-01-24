// boj 5427 fire
#include <iostream>
#include <queue>

using namespace std;

char map[1002][1002];
int w, h;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int visit[1002][1002];

struct pos {
	int r, c, cnt;
};

queue<pos> sang;
queue<pos> fire;

void solve(int tc) {
	while (!sang.empty()) {
		int len = fire.size();
		for (int i = 0; i < len; ++i) {
			pos tmpfire = fire.front();
			fire.pop();
			for (int d = 0; d < 4; ++d) {
				int fr = tmpfire.r + dr[d];
				int fc = tmpfire.c + dc[d];

				if (map[fr][fc] != '.' || visit[fr][fc] == tc) continue;
				visit[fr][fc] = tc;
				fire.push({ fr, fc, tmpfire.cnt + 1 });
			}
		}
		len = sang.size();
		for (int i = 0; i < len; ++i) {
			pos tmpsang = sang.front();
			sang.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = tmpsang.r + dr[d];
				int nc = tmpsang.c + dc[d];
				if (nr > h || nc > w || nr < 1 || nc < 1) {
					cout << tmpsang.cnt + 1 << '\n';
					return;
				}
				if (map[nr][nc] != '.' || visit[nr][nc] == tc) continue;
				visit[nr][nc] = tc;
				sang.push({ nr, nc, tmpsang.cnt + 1 });
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t){
		cin >> w >> h;

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					sang.push({ i,j,0 });
					visit[i][j] = t;
				}
				else if (map[i][j] == '*') {
					fire.push({ i,j,0 });
					visit[i][j] = t;
				}
			}
		}
		solve(t);
		while (!sang.empty()) sang.pop();
		while (!fire.empty()) fire.pop();
	}
}