// boj 2146 다리만들기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int ans = 1e9;
int map[100][100];
bool visit[100][100];
int dist[100][100];

struct pos {
	int r, c;
};

struct adj {
	int r, c, label;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool checkbound(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}
vector<adj> v;
queue<pos> q;
queue<adj> qq;

void labeling(int r, int c, int label) {
	q.push({ r, c });
	visit[r][c] = true;
	map[r][c] = label;

	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = curr + dr[i];
			int nc = curc + dc[i];
			if (!checkbound(nr, nc) || visit[nr][nc]) continue;

			if (!map[nr][nc]) {
				v.push_back({ nr, nc, label });
				visit[nr][nc] = true;
				continue;
			}
			visit[nr][nc] = true;
			map[nr][nc] = label;
			q.push({ nr, nc });
		}
	}
}

void makedist(int idx) {
	int reg = v[idx].label;
	while (!qq.empty())qq.pop();
	for (int i = 0; i < n; ++i)
		fill_n(visit[i], n, 0);
	qq.push({ v[idx].r, v[idx].c, 0 });
	visit[v[idx].r][v[idx].c] = true;

	while (!qq.empty()) {
		int curr = qq.front().r;
		int curc = qq.front().c;
		int curdist = qq.front().label;
		qq.pop();
		if (curdist >= ans) return;
		for (int i = 0; i < 4; ++i) {
			int nr = curr + dr[i];
			int nc = curc + dc[i];
			if (!checkbound(nr, nc) || visit[nr][nc]) continue;
			if (map[nr][nc] != 0 && map[nr][nc] != reg) {
				ans = curdist + 1;
				return;
			}
			else {
				visit[nr][nc] = true;
				qq.push({ nr, nc,curdist + 1 });
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	int label = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j] && map[i][j])
				labeling(i, j, label++);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		makedist(i);
	}
	cout << ans;
}