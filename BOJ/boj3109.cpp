// boj 3109 »§Áý
#include <iostream>

using namespace std;

int n, m;
int ans = 0;
char map[10002][502];
bool visit[10001][501];

bool check(int r, int c) {
	return r >= 1 && c >= 1 && r <= n && c <= m;
}

int dr[] = { -1, 0, 1 };

int search(int r, int c) {
	if (c == m) return 1;

	for (int i = 0; i < 3; ++i) {
		int nr = r + dr[i];
		int nc = c + 1;
		if (!check(nr, nc) || map[nr][nc] =='x' || visit[nr][nc]) continue;
		visit[nr][nc] = true;
		int ret = search(nr, nc);
		if (ret) return ret;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];

	for (int i = 1; i <= n; ++i) {
		ans+=search(i, 1);
	}
	cout << ans;
}
