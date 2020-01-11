// boj 16235 나무재테크

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int map[11][11];
int retech[11][11];
int dr[8] = { -1,-1,-1,0,0,1,1,1 };
int dc[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> trees[11][11];

void springandsummer() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (trees[i][j].empty()) continue;
			sort(trees[i][j].begin(), trees[i][j].end());
			int idx=-1;
			for (int res = 0; res < trees[i][j].size(); ++res) {
				if (trees[i][j][res] <= retech[i][j]) {
					retech[i][j] -= trees[i][j][res];
					trees[i][j][res] += 1;
				}
				else {
					idx = res;
					break;
				}
			}
			if (idx != -1) {
				while (trees[i][j].size() > idx) {
					retech[i][j] += trees[i][j].back()/2;
					trees[i][j].pop_back();
				}
			}
		}
	}
}
void fall() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (trees[i][j].empty()) continue;
			for (int res = 0; res < trees[i][j].size(); ++res) {
				if (trees[i][j][res] %5==0) {
					for (int dir = 0; dir < 8; ++dir) {
						int nr = i + dr[dir];
						int nc = j + dc[dir];
						if (nr<1 || nc<1 || nr>n || nc>n) continue;
						trees[nr][nc].push_back(1);
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			retech[i][j] += map[i][j];
}

void solve() {
	for (int i = 0; i < k; ++i) {
		springandsummer();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans += trees[i][j].size();
		}
	}

	cout << ans;
}


int main(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			retech[i][j]=5;
		}
	}
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}
	solve();
}