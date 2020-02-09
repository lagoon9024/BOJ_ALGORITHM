// boj 2933 ¹Ì³×¶ö
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char mineral[101][101];
bool isground[5001];
int visit[100][100];
int r, c, n;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};

vector<pos> cluster[5001];
vector<pos> bottompoint[5001];

bool boundcheck(int row, int col) {
	return row >= 0 && col >= 0 && row < r && col < c;
}

void move(int idx) {
	int movecnt = 1e5;
	for (int i = 0; i < bottompoint[idx].size(); ++i) {
		int row = 0;
		while (mineral[bottompoint[idx][i].r + row][bottompoint[idx][i].c] != 'x' && bottompoint[idx][i].r + row < r) ++row;
		if (movecnt > row) movecnt = row;
	}
	--movecnt;
	for (int i = 0; i < cluster[idx].size(); ++i) {
		cluster[idx][i].r += movecnt;
		mineral[cluster[idx][i].r][cluster[idx][i].c] = 'x';
	}
	bottompoint[idx].clear();
	cluster[idx].clear();
}

void labeling(int row, int col, int label) {
	if (row == r - 1)
		isground[label] = true;
	else
		isground[label] = false;
	queue<pos> q;
	q.push(pos(row, col));
	cluster[label].push_back(pos(row, col));
	visit[row][col] = label;

	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = curr + dr[i];
			int nc = curc + dc[i];
			if (mineral[nr][nc] == 'x' && !visit[nr][nc] && boundcheck(nr, nc)) {
				if (nr == r - 1) isground[label] = true;
				visit[nr][nc] = label;
				q.push(pos(nr, nc));
				if (!isground[label])cluster[label].push_back(pos(nr, nc));
			}
		}
	}
	if (isground[label]) {
		cluster[label].clear();
		return;
	}
	for (int j = 0; j < c; ++j) {
		for (int i = r - 1; i >= 0; --i) {
			if (visit[i][j] == label) {
				bottompoint[label].push_back(pos(i, j));
				break;
			}
		}
	}
	for (int i = 0; i < cluster[label].size(); ++i)
		mineral[cluster[label][i].r][cluster[label][i].c] = '.';
}

int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> mineral[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		fill_n(isground, 5001, true);
		int height;
		cin >> height;
		height = r - height;
		int width;
		if (i & 1) {
			width = c - 1;
			while (mineral[height][width] == '.' && width >= 0) {
				--width;
			}
		}
		else {
			width = 0;
			while (mineral[height][width] == '.' && width < c) {
				++width;
			}
		}
		if (width < 0 || width >= c) continue;
		int label = 1;
		mineral[height][width] = '.';
		for (int j = 0; j < r; ++j) fill_n(visit[j], c, 0);
		for (int dir = 0; dir < 4; ++dir) {
			int nr = height + dr[dir];
			int nc = width + dc[dir];
			if (mineral[nr][nc] == 'x' && boundcheck(nr, nc) && !visit[nr][nc]) {
				labeling(nr, nc, label);
				++label;
			}
		}
		for (int idx = 1; idx < label; ++idx) {
			if (!isground[idx]) move(idx);
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << mineral[i][j];
		}
		cout << '\n';
	}
}