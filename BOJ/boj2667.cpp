#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

char map[25][25];
int chk[25][25];

typedef struct {
	int r, c;
}pos;

int N;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };


int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);

	queue<pos> q;
	int cnt[626] = { 0 };
	int cntp=1;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}*/
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '0' || chk[i][j] != 0)continue;
			else{
				q.push({ i,j });
			//	printf("%d, %d\n", q.front().r, q.front().c);
				chk[i][j] = 1;
				while (!q.empty()) {
					pos tmp = q.front();
					q.pop();
					cnt[cntp]++;
					for (int k = 0; k < 4; k++) {
						int nr = tmp.r + dr[k];
						int nc = tmp.c + dc[k];

						if (nr < 0 || nc < 0 || nr >= N || nc >= N || chk[nr][nc] != 0 || map[nr][nc]=='0') continue;
						chk[nr][nc] = cntp;
						q.push({ nr,nc });
					}
				}
				cntp++;
			}
		}
	}

	printf("%d\n", cntp - 1);
	sort(cnt, cnt+cntp);
	for (int i = 1; i < cntp; i++)
		printf("%d\n", cnt[i]);

}