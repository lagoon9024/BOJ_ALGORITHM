//boj 17472
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int map[10][10];
int visit[10][10];
int island[7][7];
int region;
int dr[4] = { -1, 0, 1, 0 };// up left down right
int dc[4] = { 0, -1, 0, 1 };
int ans = 0;

typedef struct {
	int r, c;
}pos;

typedef struct {
	int start, goal, dist;
}sgd;

struct cmp {
	bool operator()(sgd a, sgd b) {
		return a.dist > b.dist;
	}
};

void findisland(pos sp) {
	queue<pos> q;
	q.push({ sp.r,sp.c });
	map[sp.r][sp.c] = region;
	visit[sp.r][sp.c] = 1;

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (visit[nr][nc] == 1 || map[nr][nc] == 0) continue;

			visit[nr][nc] = 1;
			map[nr][nc] = region;
			q.push({ nr,nc });
		}
	}
}

void makebridge(pos sp) {
	queue<pos> q;
	q.push({ sp.r,sp.c });
	visit[sp.r][sp.c] = 1;
	int regnum = map[sp.r][sp.c];

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (visit[nr][nc] == 1) continue;

			if (map[nr][nc] == regnum) {
				visit[nr][nc] = 1;
				q.push({ nr,nc });
			}
			else if (map[nr][nc] == 0) {
				int j;
				switch (i) {
				case 0:
					j = -1;
					while (map[nr + j][nc] == 0 && nr + j > 0) j--;
					if (map[nr + j][nc] == regnum) break;
					else if (map[nr + j][nc] != 0) {
						if ((island[regnum][map[nr + j][nc]] == 0 || island[regnum][map[nr + j][nc]] > (j * (-1))) && j < -1)
							island[regnum][map[nr + j][nc]] = island[map[nr + j][nc]][regnum] = j * (-1);
					}
					break;
				case 1:
					j = -1;
					while (map[nr][nc + j] == 0 && nc + j > 0) j--;
					if (map[nr][nc + j] == regnum) break;
					else if (map[nr][nc + j] != 0) {
						if ((island[regnum][map[nr][nc + j]] == 0 || island[regnum][map[nr][nc + j]] > (j * (-1))) && j < -1)
							island[regnum][map[nr][nc + j]] = island[map[nr][nc + j]][regnum] = j * (-1);
					}
					break;
				case 2:
					j = 1;
					while (map[nr + j][nc] == 0 && nr + j < N - 1) j++;
					if (map[nr + j][nc] == regnum) break;
					else if (map[nr + j][nc] != 0) {
						if ((island[regnum][map[nr + j][nc]] == 0 || island[regnum][map[nr + j][nc]] > j) && j > 1)
							island[regnum][map[nr + j][nc]] = island[map[nr + j][nc]][regnum] = j;
					}
					break;
				case 3:
					j = 1;
					while (map[nr][nc + j] == 0 && nc + j < M - 1) j++;
					if (map[nr][nc + j] == regnum) break;
					else if (map[nr][nc + j] != 0) {
						if ((island[regnum][map[nr][nc + j]] == 0 || island[regnum][map[nr][nc + j]] > j) && j > 1)
							island[regnum][map[nr][nc + j]] = island[map[nr][nc + j]][regnum] = j;
					}
					break;
				}
			}
		}
	}
}

int getpar(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getpar(set, set[x]);
}

void Unionpar(int set[], int a, int b) {
	a = getpar(set, a);
	b = getpar(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int set[], int x, int y) {
	x = getpar(set, x);
	y = getpar(set, y);

	if (x == y) return 1;
	else return 0;
}

void findpath() {
	priority_queue<sgd, vector<sgd>, cmp> pq;
	int set[7];
	for (int i = 1; i <= region; i++) {
		set[i] = i;
		for (int j = i; j <= region; j++) {
			if (island[i][j] == 0) continue;
			else
				pq.push({ i,j,island[i][j] });
		}
	}

	while (!pq.empty()) {
		sgd tmp = pq.top();
		pq.pop();
		if (!find(set, tmp.start, tmp.goal)) {
			ans += tmp.dist;
			//cout << "SP : " << tmp.start << " EP : " << tmp.goal <<" dist : "<< tmp.dist << '\n';
			Unionpar(set, tmp.start, tmp.goal);
		}
	}
	for (int i = 1; i <= region; i++) {
		if (getpar(set,set[i]) != 1) ans = 0;
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	region = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0 && map[i][j] != 0) {
				region++;
				findisland({ i,j });
			}
		}
	}
	if (region > 0) {
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visit[i][j] == 0 && map[i][j] != 0) {
					makebridge({ i,j });
				}
			}
		}
		findpath();
	}
	if (ans == 0) cout << -1;
	else cout << ans;
}