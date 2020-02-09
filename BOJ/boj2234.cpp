//boj 2234 ¼º°û
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, maxsize;
int map[50][50];
int visit[50][50];
vector<int> regsize;
vector<int> adj[2501];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};

void bfs(int r, int c, int label) {
	queue<pos> q;
	q.push(pos(r, c));
	visit[r][c] = label;
	int size = 1;
	while (!q.empty()) {
		int curr = q.front().r;
		int curc = q.front().c;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if ((1 << i) & map[curr][curc]) continue;
			int nr = curr + dr[i];
			int nc = curc + dc[i];
			if (visit[nr][nc] == label) continue;
			visit[nr][nc] = label;
			++size;
			q.push(pos(nr, nc));
		}
	}
	if (size > maxsize) maxsize = size;
	regsize.push_back(size);
}

int main(void) {
	maxsize = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	int label = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j])
			{
				bfs(i, j, label);
				++label;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int d = 0; d < 4; ++d) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr < 0 || nc < 0 || nr >= m || nc >= n)continue;
				if (visit[i][j] != visit[nr][nc]) {
					adj[visit[i][j]].push_back(visit[nr][nc]);
					adj[visit[nr][nc]].push_back(visit[i][j]);
				}
			}
		}
	}
	int maxmerged = 0;
	for (int i = 1; i < label; ++i) {
		for (int j = 0; j<adj[i].size(); ++j) {
			int tmpmerge = regsize[i - 1] + regsize[adj[i][j] - 1];
			if (tmpmerge > maxmerged) maxmerged = tmpmerge;
		}
	}
	cout << label - 1 << '\n' << maxsize << '\n' << maxmerged;
}