#include <iostream>

using namespace std;

int W, D, K, ans;
int map[13][20];
int originmap[13][20];
int flag;

bool check() {
	for (int i = 0; i < W; i++) {
		int cnt = 0;
		for (int j = 0; j < D; j++) {
			cnt++;
			if (j > 0 && map[j][i] != map[j - 1][i]) cnt = 1;
			if (cnt >= K) break;
		}
		if (cnt < K) {
			return false;
		}
	}
	return true;
}

void insert(int r, int chem) {
	if (chem == 0) {
		for (int i = 0; i < W; i++) {
			map[r][i] = 0;
		}
	}
	else {
		for (int i = 0; i < W; i++) {
			map[r][i] = 1;
		}
	}
}
void reset(int r) {
	for (int i = 0; i < W; i++)
		map[r][i] = originmap[r][i];
}

void dfs(int depth, int p) {
	if (check()) {
		if (ans == -1 || depth < ans) ans = depth;
		flag = 1;
		return;
	}
	if (flag == 1 && depth >= ans) return;
	for (int i = p; i < D; i++) {
		for (int j = 0; j < 2; j++) {
			insert(i, j);
			dfs(depth + 1, i + 1);
			reset(i);
		}
	}
}


int main(void) {
	int T;

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				originmap[i][j] = map[i][j];
			}
		}
		ans = -1;
		flag = 0;
		dfs(0, 0);

		cout << "#" << tc << " " << ans << '\n';
	}
}