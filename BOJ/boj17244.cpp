// boj 17244 아맞다우산
#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
bool visit[51][51][1 << 5];
int n, m;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct pos {
	int r, c, time, thing;
};

int main(void) {
	cin >> m >> n;
	int thingcnt = 0;

	queue<pos> kyung;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				kyung.push({ i,j,0,0 });
				visit[i][j][0] = true;
			}
			else if (map[i][j] == 'X') {
				map[i][j] = '0' + thingcnt++;
			}
		}
	}

	while (!kyung.empty()) {
		pos now = kyung.front();
		kyung.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int nthing = now.thing;

			if (map[nr][nc] == 'E') {
				if (now.thing == (1 << thingcnt) - 1) {
					cout << now.time + 1;
					return 0;
				}
				continue;
			}
			if (map[nr][nc] == '#' || visit[nr][nc][now.thing]) continue;
			if ((map[nr][nc] - '0') >= 0 && (map[nr][nc] - '0') <= 4) {
				nthing = now.thing | (1 << (map[nr][nc] - '0'));
			}
			visit[nr][nc][nthing] = true;
			kyung.push({ nr,nc,now.time + 1,nthing });
		}
	}

	return 0;
}