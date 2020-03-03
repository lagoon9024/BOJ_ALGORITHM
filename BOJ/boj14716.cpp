// boj 14716 Çö¼ö¸·
#include <iostream>
#include <queue>

using namespace std;
int planc[250][250];
bool visit[250][250];
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int dr[] = { -1,-1,-1,1,1,1,0,0 };
	int dc[] = { -1,0,1,-1,0,1,-1,1 };
	int row, col, label = 0;
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> planc[i][j];
		}
	}

	queue<pos> q;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (planc[i][j] && !visit[i][j]) {
				++label;
				q.push(pos(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					int curr = q.front().r;
					int curc = q.front().c;
					q.pop();
					for (int d = 0; d < 8; ++d) {
						int nr = curr + dr[d];
						int nc = curc + dc[d];
						if (nr < 0 || nc < 0 || nr >= row || nc >= col || visit[nr][nc] || !planc[nr][nc]) continue;
						visit[nr][nc] = true;
						q.push(pos(nr, nc));
					}
				}
			}
		}
	}
	cout << label;
}