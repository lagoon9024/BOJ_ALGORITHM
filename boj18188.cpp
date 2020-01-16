// boj 18188 dao's date
#include <iostream>
#include <vector>

using namespace std;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct movedir {
	char dir1, dir2;
};

int daor, daoc, dizr, dizc;
bool flag;
char bubblehill[21][21];
int h, w, n;
vector<char> path;
vector<movedir> dao;

bool check(int r, int c) {
	return r > 0 && c > 0 && r <= h && c <= w;
}

void finddiz(int r, int c, int movecnt) {
	if (movecnt >= n) return;
	if (flag) return;

	char direction[] = { dao[movecnt].dir1, dao[movecnt].dir2 };
	for (int i = 0; i < 2; ++i) {
		int dir;
		switch (direction[i]) {
		case 'W':
			dir = 0;
			break;
		case 'A':
			dir = 2;
			break;
		case 'S':
			dir = 1;
			break;
		case 'D':
			dir = 3;
			break;
		}
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (!check(nr, nc) || bubblehill[nr][nc] == '@')continue;
		path.push_back(direction[i]);
		if (bubblehill[nr][nc] == 'Z') {
			cout << "YES\n";
			for (int j = 0; j < path.size(); ++j) {
				cout << path[j];
			}
			flag = true;
			return;
		}
		finddiz(nr, nc, movecnt + 1);
		path.pop_back();
	}
}

int main(void) {
	cin >> h >> w;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> bubblehill[i][j];
			if (bubblehill[i][j] == 'D') {
				daor = i; daoc = j;
			}
			else if (bubblehill[i][j] == 'Z') {
				dizr = i; dizc = j;
			}
		}
	}
	cin >> n;

	for (int i = 0; i < n; ++i) {
		movedir tmp;
		cin >> tmp.dir1 >> tmp.dir2;
		dao.push_back(tmp);
	}

	finddiz(daor, daoc, 0);
	if (path.empty()) cout << "NO";
}