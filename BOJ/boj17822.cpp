//boj 17822
#include <iostream>
#include <vector>

using namespace std;

int circularboard[51][51];
int N, M, T;
int boardidx[50];
typedef struct pos {
	int r, c;
};


void merge() {
	vector<pos> v;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circularboard[i][j] == -1) continue;
			if (j - 1 != 0) {
				if (circularboard[i][j] == circularboard[i][j - 1]) {
					v.push_back({ i,j });
					v.push_back({ i, j - 1 });
				}
			}
			else {
				if (circularboard[i][j] == circularboard[i][M]) {
					v.push_back({ i,j });
					v.push_back({ i, M });
				}
			}

		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 2; j <= N; j++) {
			int idx = (circularboard[j][0] + M + i - 1) % M;
			if (idx == 0) idx = M;
			int tmpidx = (circularboard[j - 1][0] + M + i - 1) % M == 0 ? M : (circularboard[j - 1][0] + M + i - 1) % M;
			if (circularboard[j][idx] == -1) continue;
			if (circularboard[j][idx] == circularboard[j - 1][tmpidx]) {
				v.push_back({ j,idx });
				v.push_back({ j - 1, tmpidx });
			}
		}
	}
	if (v.empty()) {
		float avg = 0;
		int cnt = N * M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (circularboard[i][j] == -1) {
					cnt--;
					continue;
				}
				avg += circularboard[i][j];
			}
		}
		avg = avg / cnt;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (circularboard[i][j] == -1) continue;
				if (avg > circularboard[i][j]) circularboard[i][j]++;
				else if (circularboard[i][j] > avg) circularboard[i][j]--;
			}
		}
	}
	while (!v.empty()) {
		pos tmp = v[v.size() - 1];
		circularboard[tmp.r][tmp.c] = -1;
		v.pop_back();
	}
}

	int main(void) {
		cin >> N >> M >> T;
		for (int i = 1; i <= N; i++) {
			circularboard[i][0] = 1;
			for (int j = 1; j <= M; j++) {
				cin >> circularboard[i][j];
			}
		}
		for (int i = 0; i < T; i++) {
			int x, d, k;
			cin >> x >> d >> k;
			for (int j = 1; j <= N; j++) {
				if (j % x == 0) {
					if (d == 0)
						circularboard[j][0] = (circularboard[j][0] + M - k) % M;
					else
						circularboard[j][0] = (circularboard[j][0] + k) % M;
					
					if (circularboard[j][0] == 0) circularboard[j][0] = M;
				}
			}
			merge();
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (circularboard[i][j] == -1) continue;
				ans += circularboard[i][j];
			}
		}
		cout << ans;
	}