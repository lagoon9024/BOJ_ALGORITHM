#include <iostream>
#include <cstring>

using namespace std;

typedef struct cut {
	int dir;
	int pos;
}cut;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
bool chk[100][100];

int localcnt = 0;

void counting(int** paper, int R, int C, int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= R || nc >= C || chk[nr][nc] == true) continue;
		if (paper[nr][nc] == paper[r][c]) {
			chk[nr][nc] = true;
			localcnt++;
			counting(paper, R, C, nr, nc);
		}
	}
}

int cutting(int** paper, cut* cuts, int R, int C, int N) {
	for (int k = 0; k < N; k++) {
		int r = 0; 
		int c = 0;
		if (cuts[k].dir == 0)
			r = cuts[k].pos;
		else if (cuts[k].dir == 1)
			c = cuts[k].pos;
		for (int i = r; i < R; i++) {
			for (int j = c; j < C; j++) {
				paper[i][j]++;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (chk[i][j]==false && ((i > 0 && paper[i][j] != paper[i - 1][j]) || (j > 0 && paper[i][j] != paper[i][j - 1]))) {
				localcnt = 1;
				chk[i][j] = true;
				counting(paper, R, C, i, j);
				max = max > localcnt ? max : localcnt;
			}
		}
	}

	return max;
}



int main(void) {
	int R, C, N;

	cin >> C >> R;

	int** paper = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++)
		paper[i] = (int*)malloc(sizeof(int) * C);

	cin >> N;
	memset(chk, false, sizeof(chk));
	cut* cuts = (cut*)malloc(sizeof(cut) * N);
	for (int i = 0; i < N; i++) {
		cin >> cuts[i].dir >> cuts[i].pos;
	}
	int res = cutting(paper, cuts, R, C, N);

	cout << res << '\n';

	for (int i = 0; i < R; i++)
		free(paper[i]);
	free(paper);
	free(cuts);
}