//boj16234
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

int N, L, R;
int map[50][50];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int flag = 0;
int check[50][50];

typedef struct {
	int r, c;
}pos;
using namespace std;

void movemove(int r, int c) {
	queue<pos> q;
	vector<pos> v;
	check[r][c] = 1;
	v.push_back({ r,c });
	q.push({ r,c });
	int total = 0;
	total += map[r][c];

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc] == 1) continue;
			if (abs(map[nr][nc] - map[tmp.r][tmp.c]) >= L && abs(map[nr][nc] - map[tmp.r][tmp.c]) <= R) {
				check[nr][nc] = 1;
				v.push_back({ nr,nc });
				total += map[nr][nc];
				q.push({ nr,nc });
			}
		}
	}
	int uvalue = total / v.size();
	for (int i = 0; i < v.size(); i++) {
		map[v[i].r][v[i].c] = uvalue;
	}
}

int main(void) {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	int ans = 0;
	for (int cnt = 0; cnt <= 2000; cnt++) {
		memset(check, 0, sizeof(check));
		int tcnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0) {
					tcnt++;
					movemove(i, j);
				}				
			}
			if (tcnt == N * N) flag = 1;
		}
		if (flag == 1) { ans = cnt; break; }
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}*/
	cout << ans;
}