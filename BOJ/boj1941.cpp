//boj 1941 소문난 칠공주
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char SY[6][6];
int ans = 0;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,1,-1 };
bool visit[5][5];
struct pos {
	int r, c;
};
vector<int> complex;

bool checkconnect() {
	int cnt = 0;
	int scnt = 0;
	int ycnt = 0;
	int map[5][5];
	for (int i = 0; i < 5; i++) {
		fill_n(map[i], 5, 0);
		fill_n(visit[i], 5, false);
	}
	for (int i = 0; i < complex.size(); ++i) {
		int r = complex[i] / 5;
		int c = complex[i] % 5;
		if (SY[r][c] == 'S') scnt++;
		else ycnt++;
		map[r][c] = 1;
	}

	if (ycnt > 3) return false;

	queue<pos> q;
	q.push({ complex[0] / 5,complex[0] % 5 });
	if (SY[complex[0] / 5][complex[0] % 5] == 'S') scnt++;
	else ycnt++;

	visit[complex[0] / 5][complex[0] % 5] = true;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || visit[nr][nc] || map[nr][nc]==0) continue;
			visit[nr][nc] = true;
			q.push({ nr,nc });
		}
	}
	if (cnt == 7) return true;
	return false;
}

void make(int r, int depth) {
	if (depth == 7) {
		if (checkconnect()) ans++;
		// cout << complex.size() << '\n';
		return;
	}

	for (int i = r + 1; i < 25; i++) {
		complex.push_back(i);
		make(i, depth + 1);
		complex.pop_back();
	}
}


int main(void) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> SY[i][j];

	for (int i = 0; i < 25; i++) {
		complex.push_back(i);
		make(i,1);
		complex.pop_back();
	}
	cout << ans;
}