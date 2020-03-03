#include <iostream>

using namespace std;
int n, map[3 * 3 * 3 * 3 * 3 * 3 * 3][3 * 3 * 3 * 3 * 3 * 3 * 3], ans[3];

void go(int r, int c, int num) {
	int val = map[r][c];
	bool allsame = true;
	for (int i = r; i < r + num; ++i) {
		if (!allsame) break;
		for (int j = c; j < c + num; ++j) {
			if (map[i][j] != val) {
				allsame = false;
				break;
			}
		}
	}
	if (allsame) ++ans[val + 1];
	else {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				go(r + num / 3 * i, c + num / 3 * j, num / 3);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];

	go(0, 0, n);
	for (int i = 0; i < 3; ++i) cout << ans[i] << '\n';
}