//BOJ 14890
#include <iostream>

using namespace std;

int N, M;
int map[100][100];
bool visit[100];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int flag = 0;
		fill_n(visit, 100, false);
		for (int j = 1; j < N; j++) {
			if (flag == 1) break;
			if (map[i][j] == map[i][j - 1]) continue;
			else if (map[i][j] != map[i][j - 1]) {
				int stair;
				if ((map[i][j] - map[i][j - 1]) == 1) {
					stair = map[i][j - 1];
					if (j < M) {
						flag = 1;
					}
					else {
						for (int k = 1; k <= M; k++) {
							if (map[i][j - k] == stair && visit[j - k] == false) {
								visit[j - k] = true;
								continue;
							}
							else {
								flag = 1;
								break;
							}
						}
					}
				}
				else if ((map[i][j] - map[i][j - 1]) == -1) {
					stair = map[i][j];
					if (j + M > N) {
						flag = 1;
					}
					else {
						for (int k = 0; k < M; k++) {
							if (map[i][j + k] == stair && visit[j + k] == false) {
								visit[j + k] = true;
								continue;
							}
							else {
								flag = 1;
								break;
							}
						}
					}
				}
				else flag = 1;
			}
		}
		if (flag == 0) {
			cnt++;// cout << "cntupi: " << i << '\n';
		}
	}

	for (int j = 0; j < N; j++) {
		int flag = 0;
		fill_n(visit, 100, false);
		for (int i = 1; i < N; i++) {
			if (flag == 1) break;
			if (map[i - 1][j] == map[i][j]) continue;
			else if (map[i][j] != map[i - 1][j]) {
				int stair;
				if ((map[i][j] - map[i - 1][j]) == 1) {
					stair = map[i - 1][j];
					if (i < M) {
						flag = 1;
					}
					else {
						for (int k = 1; k <= M; k++) {
							if (map[i - k][j] == stair && visit[i - k] == false) {
								visit[i - k] = true;
								continue;
							}
							else {
								flag = 1;
								break;
							}
						}
					}
				}
				else if ((map[i][j] - map[i - 1][j]) == -1) {
					stair = map[i][j];
					if (i + M > N) {
						flag = 1;
					}
					else {
						for (int k = 0; k < M; k++) {
							if (map[i + k][j] == stair && visit[i + k] == false) {
								visit[i + k] = true;
								continue;
							}
							else {
								flag = 1;
								break;
							}
						}
					}
				}
				else flag = 1;
			}

		}
		if (flag == 0) {
			cnt++; //cout << "cntupj: " << j << '\n';
		}
	}
	cout << cnt;
}