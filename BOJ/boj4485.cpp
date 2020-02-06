// boj 4485 ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
#include <iostream>
#include <queue>

using namespace std;
const int inf = 1e9;
int n;
int map[125][125];
int d[125][125];
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

bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}

int main(void) {
	int t=0;
	while (1) {
		++t;
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0; i < n; ++i) {
			fill_n(d[i], n, inf);
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
			}
		}
		queue <pos> q;
		q.push(pos(0, 0));
		d[0][0] = map[0][0];
		while (!q.empty()) {
			pos tmp = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];

				if (!check(nr, nc)|| d[nr][nc]<=d[tmp.r][tmp.c]+map[nr][nc]) continue;
				d[nr][nc] = d[tmp.r][tmp.c] + map[nr][nc];
				q.push(pos(nr, nc));
			}
		}
		cout << "Problem " << t << ": " << d[n-1][n-1] << '\n';
	}
}