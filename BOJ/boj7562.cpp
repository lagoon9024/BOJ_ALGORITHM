// boj 7562 나이트의 이동
#include <iostream>
#include <queue>

using namespace std;

int dr[] = { -2,-2,-1,-1,1,1,2,2 };
int dc[] = { -1,1,-2,2,-2,2,-1,1 };
int map[300][300];
int l, knightr, knightc, goalr, goalc;
bool visit[300][300];

class pos {
public:
	int r, c;
	int dist = 0;
	pos (int _r, int _c, int _dist) {
		this->r = _r;
		this->c = _c;
		this->dist = _dist;
	}
};

bool checkboundary(int r, int c) {
	return r >= 0 && c >= 0 && r < l && c < l;
}

void move() {
	if (knightr == goalr && knightc == goalc) {
		cout << 0 << '\n';
		return;
	}
	pos Pos(knightr, knightc,0);
	queue<pos> q;
	q.push(Pos);
	visit[Pos.r][Pos.c] = true;

	while (!q.empty()) {
		pos tmp(q.front().r, q.front().c,q.front().dist);
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			int ndist = tmp.dist + 1;

			if (nr == goalr && nc == goalc) {
				cout << ndist << '\n';
				return;
			}

			if (visit[nr][nc] || !checkboundary(nr, nc)) continue;
			visit[nr][nc] = true;
			q.push(pos(nr, nc, ndist));
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> l >> knightr >> knightc >> goalr >> goalc;
		for (int i = 0; i < l; ++i)
			fill_n(visit[i], l, false);
		move();
	}
}