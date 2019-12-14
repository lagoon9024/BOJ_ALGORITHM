// BOJ 15684 사다리 조작

#include <iostream>

using namespace std;

int N, M, H;
int arr[11][31];
int goal[11];
//int line[11];
int flag = 0;

int mincnt = 4;

void mmove(int sp) {
	int j = 1;
	int i = sp;
	while (j != H + 1) {
		if (arr[i][j] != 0)
			i = arr[i][j];
		j++;
	}
	goal[sp] = i;
	return;
}

void makemap(int cnt, int r, int c) {
	if (cnt > 3) return;
	if (flag == 1 && cnt >= mincnt) return;
	
	int mismatch = 0;
	for (int i = 1; i <= N; i++) {
		mmove(i);
		if (goal[i] != i) {
			mismatch++;
			break;
		}
	}
	if (mismatch == 0) {
		flag = 1;
		if (mincnt > cnt) {
			mincnt = cnt;
			return;
		}
	}


	for (int i = r; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if ((i==r && j<=c) || arr[i][j] != 0 || arr[i + 1][j] != 0) continue;
			else {
					arr[i][j] = i + 1;
					arr[i + 1][j] = i;
					makemap(cnt + 1, i, j);
					arr[i][j] = arr[i + 1][j] = 0;
			}
		}
	}
	return;
}

int main(void) {
	cin >> N >> M >> H;
	//fill_n(line, N + 1, 0);

	for (int i = 0; i < N + 1; i++) {
		fill_n(arr[i], H+1, 0);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		arr[b][a] = b + 1;
		arr[b + 1][a] = b;
		//line[b]++;
	}
	makemap(0, 1, 1);

	if (mincnt > 3)
		cout << -1;
	else
		cout << mincnt;
}