#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int map[10][10];
int chk[10][10] = { 0, };
int N, MAXW, MAXB;

bool availpos(int r, int c) {
	int f1, f2;
	f1 = r + c;
	f2 = r - c;

	for (int i = 0; i < N; i++) {
		if (i == r)continue;
		if ((i-f2 >=0 && i-f2 < N && chk[i][i - f2] == 1) ||(f1-i>=0 && f1-i<N && chk[i][f1 - i] == 1)) return false;
	}
	return true;
}

void dfs(int color, int depth, int r, int c) {
	if (color == 1 && depth > MAXW) MAXW = depth;
	if (color == 0 && depth > MAXB) MAXB = depth;
	
	int p;
	for (int i = r; i < N; i++) {
		if ((color == 0 && i % 2 == 0) || (color == 1 && i % 2 == 1)) p = 0;
		else p = 1;
		for (int j = p; j < N; j+=2) {
			if ((i==r && j<c) || map[i][j] == 0 || chk[i][j] == 1 || !availpos(i, j)) continue;
				chk[i][j] = 1;
				dfs(color, depth+1, i, j);
				chk[i][j] = 0;
		}
	}
}

int main(void) {
	setbuf(stdout,NULL);
	scanf("%d",&N);
	MAXW = MAXB = 0; 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	

	dfs(0, 0, 0, 0);
	dfs(1, 0, 0, 1);

	printf("%d\n",MAXW + MAXB);
}