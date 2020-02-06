// boj 17837 새로운 게임2
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int map[13][13];
vector<int> board[13][13];
int n, k;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

struct pos {
	int r, c, dir;
};

vector<pos> mal;
stack<int> ss;
stack<int> s;

bool checkboard(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= n;
}

void red(int r, int c) {
	while (!s.empty()) {
		mal[s.top()].r = r;
		mal[s.top()].c = c;
		ss.push(s.top());
		s.pop();
	}
	while (!ss.empty()) {
		board[r][c].push_back(ss.top());
		ss.pop();
	}
}

void white(int r, int c) {
	while (!s.empty()) {
		mal[s.top()].r = r;
		mal[s.top()].c = c;
		board[r][c].push_back(s.top());
		s.pop();
	}
}

void blue(int r, int c, int dir, int idx) {
	int nr = r - 2 * dr[dir - 1];
	int nc = c - 2 * dc[dir - 1];

	int ndir;
	if (dir % 2) ndir = dir + 1;
	else ndir = dir - 1;

	if (map[nr][nc] == 2 || !checkboard(nr, nc)) {
		nr = r - dr[dir - 1];
		nc = c - dc[dir - 1];
		mal[idx] = { nr,nc,ndir };
		while (!s.empty()) {
			board[nr][nc].push_back(s.top());
			s.pop();
		}
		return;
	}

	mal[idx] = { nr,nc,ndir };

	if (map[nr][nc] == 1)
		red(nr, nc);
	else if (map[nr][nc] == 0)
		white(nr, nc);
}

int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; ++i) {
		pos tmp;
		cin >> tmp.r >> tmp.c >> tmp.dir;
		mal.push_back(tmp);
		board[tmp.r][tmp.c].push_back(i);
	}
	int turn = 1;
	while (true) {
		if (turn >= 1000) {
			cout << -1;
			return 0;
		}
		for (int i = 0; i < k; ++i) {

			pos tmp = mal[i];

			while (board[tmp.r][tmp.c].back() != i) {
				s.push(board[tmp.r][tmp.c].back());
				board[tmp.r][tmp.c].pop_back();
			}
			s.push(i);
			board[tmp.r][tmp.c].pop_back();

			int nr = tmp.r + dr[tmp.dir - 1];
			int nc = tmp.c + dc[tmp.dir - 1];

			if (!checkboard(nr, nc) || map[nr][nc] == 2)
				blue(nr, nc, tmp.dir, i);
			else if (map[nr][nc] == 1)
				red(nr, nc);
			else
				white(nr, nc);
			if (board[mal[i].r][mal[i].c].size() >= 4) {
				cout << turn;
				return 0;
			}
		}
		++turn;
	}
}