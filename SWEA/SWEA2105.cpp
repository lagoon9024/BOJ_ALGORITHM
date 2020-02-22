// swea 2105 디저트카페
#include <iostream>

using namespace std;
int n,ans;
int cafe[20][20];
bool eat[101];
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
	bool bound() {
		return r >= 0 && c >= 0 && r < n && c < n;
	}
};

int dr[] = { -1,1,1,-1 };
int dc[] = { 1,1,-1,-1 };

void go(pos start, pos cur, int dir, int depth) {
	for (int i = 0; i < 2; ++i) {
		pos next(cur.r + dr[dir+i], cur.c + dc[dir+i]);
		if (next.r == start.r && next.c == start.c) {
			if (ans < depth) ans = depth;
			continue;
		}
		if (!next.bound() || eat[cafe[next.r][next.c]]) continue;
		eat[cafe[next.r][next.c]] = true;
		go(start, next, dir + i, depth + 1);
		eat[cafe[next.r][next.c]] = false;
	}
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		ans = -1;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> cafe[i][j];
			}
		}

		for (int i = 1; i < n - 1; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				eat[cafe[i][j]] = true;
				go(pos(i, j), pos(i, j), 0, 1);
				eat[cafe[i][j]] = false;
			}
		}


		cout << '#' << tc << " " << ans<<'\n';
	}
}