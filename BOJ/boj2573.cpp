// boj 2573 ºù»ê
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int visit[300][300];
int map[300][300];
int del[10000];
int n, m, icecnt;
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
vector<pos> points;
bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j]) {
				points.push_back(pos(i, j));
				++icecnt;
			}
		}
	}

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	for (int i = 0; i < n; ++i)
		fill_n(visit[i], m, -1);
	int ans = 0;
	while (icecnt) {
		queue<pos> q;
		fill_n(del, points.size(), 0);
		for (int i = 0; i < points.size(); ++i) {
			int rr = points[i].r;
			int cc = points[i].c;
			if (map[rr][cc] > 0) {
				q.push(points[i]);
				visit[rr][cc] = ans;
				break;
			}
		}
		int nowcnt = q.size();
		while (!q.empty()) {
			pos tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];
				if (visit[nr][nc] == ans || !check(nr, nc) || !map[nr][nc]) continue;
				visit[nr][nc] = ans;
				q.push(pos(nr, nc));
				++nowcnt;
			}
		}
		if (nowcnt == icecnt) {
			for (int i = 0; i < points.size(); ++i) {
				int rr = points[i].r;
				int cc = points[i].c;
				if (map[rr][cc] > 0) {
					for (int d = 0; d < 4; ++d) {
						int nr = rr + dr[d];
						int nc = cc + dc[d];
						if(!map[nr][nc]) ++del[i];
					}					
				}
			}
			for (int i = 0; i < points.size(); ++i) {
				int rr = points[i].r;
				int cc = points[i].c;
				if (!map[rr][cc]) continue;
				map[rr][cc] -= del[i];
				if (map[rr][cc] < 0) map[rr][cc] = 0;
				if (!map[rr][cc]) --icecnt;
			}
		}		
		else {
			cout << ans;
			return 0;
		}
		++ans;
	}
	cout << 0;
}