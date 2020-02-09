// boj 2174 ·Îº¿ ½Ã¹Ä·¹ÀÌ¼Ç
#include <iostream>

using namespace std;

int a, b, n, m;
int map[101][101];
int dr[] = { -1,0,1,0 }; //W S E N;
int dc[] = { 0,-1,0,1 };
class pos {
public:
	int r, c, dir;
	pos() {
		this->r = -1;
		this->c = -1;
		this->dir = -1;
	}
	pos(int rr, int cc, int dd) {
		this->r = rr;
		this->c = cc;
		this->dir = dd;
	}
};
pos robots[101];

int main(void) {
	cin >> a >> b >> n >> m;
	char dir;
	for (int i = 1; i <= n; ++i) {
		cin >> robots[i].r >> robots[i].c >> dir;
		if (dir == 'W') robots[i].dir = 0;
		else if (dir == 'S') robots[i].dir = 1;
		else if (dir == 'E') robots[i].dir = 2;
		else robots[i].dir = 3;
		map[robots[i].r][robots[i].c] = i;
	}
	for (int i = 0; i < m; ++i) {
		int idx, loop;
		cin >> idx >> dir >> loop;
		int cdir;
		if (dir == 'F') cdir = 0;
		else if (dir == 'L') cdir = 1;
		else cdir = -1;
		map[robots[idx].r][robots[idx].c] = 0;
		while (loop--) {
			int nextdir = robots[idx].dir + cdir;
			if (nextdir < 0) nextdir += 4;
			else if (nextdir > 3) nextdir -= 4;
			robots[idx].dir = nextdir;
			if (!cdir) {
				robots[idx].r += dr[nextdir];
				robots[idx].c += dc[nextdir];
			}
			if (map[robots[idx].r][robots[idx].c]) {
				cout << "Robot " << idx << " crashes into robot " << map[robots[idx].r][robots[idx].c];
				return 0;
			}
			else if (robots[idx].r <= 0 || robots[idx].c <= 0 || robots[idx].r > a || robots[idx].c > b) {
				cout << "Robot " << idx << " crashes into the wall";
				return 0;
			}
		}
		map[robots[idx].r][robots[idx].c] = idx;
	}
	cout << "OK";
}