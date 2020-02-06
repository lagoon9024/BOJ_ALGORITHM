// boj 2638 cheese
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][100];
bool visit[100][100];
struct pos {
	int r, c;
};

int main(void) {
	int n, m;
	vector<pos> cheese;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j]) cheese.push_back({ i,j });
		}
	}

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	vector<int> bye;
	vector<pos> nextcheese;
	int ans = 0;
	queue<pos> q;
	while (!cheese.empty()) {
		for (int i = 0; i < n; ++i)
			fill_n(visit[i], m, false);
		
		q.push({ 0,0 });
		visit[0][0] = true;
		while (!q.empty()) {
			pos tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc] || map[nr][nc]) continue;
				visit[nr][nc] = true;
				q.push({ nr,nc });
			}
		}

		++ans;
		for (int i = 0; i < cheese.size(); ++i) {
			int aircnt = 0;
			for (int d = 0; d < 4; ++d) {
				int nr = cheese[i].r + dr[d];
				int nc = cheese[i].c + dc[d];
				if (!map[nr][nc]&&visit[nr][nc]) ++aircnt;
			}
			if (aircnt > 1) bye.push_back(i);
			else nextcheese.push_back(cheese[i]);
		}
		for (int i = 0; i < bye.size(); ++i)
			map[cheese[bye[i]].r][cheese[bye[i]].c] = 0;

		bye.clear();
		cheese.clear();
		while (!nextcheese.empty()) {
			cheese.push_back(nextcheese.back());
			nextcheese.pop_back();
		}
	}
	cout << ans;
}