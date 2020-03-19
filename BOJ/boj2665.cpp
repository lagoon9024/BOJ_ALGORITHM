// boj 2665 미로 만들기
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
int n, map[50][50], brokecnt[50][50], ans;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool cango(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}

void search(int r, int c) {
	queue<pos> q;
	q.push(pos(r, c));
	brokecnt[r][c] = 0;
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (cango(nr, nc) && (brokecnt[nr][nc] == -1 || brokecnt[nr][nc] > brokecnt[cur.r][cur.c])) {
				if (!map[nr][nc]) brokecnt[nr][nc] = brokecnt[cur.r][cur.c] + 1;
				else brokecnt[nr][nc] = brokecnt[cur.r][cur.c];
				q.push(pos(nr, nc));
			}
		}
	}
}

int main(void) {
	ans = 1e9;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
			brokecnt[i][j] = -1;
		}
	}
	search(0, 0);
	cout << brokecnt[n - 1][n - 1];
}