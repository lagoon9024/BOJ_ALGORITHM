// boj 17406 배열돌리기 4
#include <iostream>

using namespace std;

int n, m, k,ans, board[51][51], map[51][51];
int rot[6][3];
int seosun[6];

void rotate(int idx) {
	int rs, re, cs, ce;
	rs = rot[idx][0] - rot[idx][2];
	re = rot[idx][0] + rot[idx][2];
	cs = rot[idx][1] - rot[idx][2];
	ce = rot[idx][1] + rot[idx][2];
	while (rs != re) {
		int rue = map[rs][ce];
		int lde = map[re][cs];
		for (int i = cs; i < ce; ++i) {			
			map[re][i] = map[re][i + 1];
		}
		for (int i = ce; i > cs; --i) {
			map[rs][i] = map[rs][i - 1];
		}
		for (int i = rs; i < re; ++i) {
			map[i][cs] = map[i + 1][cs];
		}
		for (int i = re; i > rs; --i) {
			map[i][ce] = map[i - 1][ce];
		}
		map[re - 1][cs] = lde;
		map[rs + 1][ce] = rue;
		++rs; --re; ++cs; --ce;
	}
}

void makeseosun(int depth, int flag) {
	if (flag==(1<<k)-1) {
		for (int i =1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				map[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < k; ++i)
			rotate(seosun[i]);

		int val;
		for (int i = 1; i <= n; ++i) {
			val = 0;
			for (int j = 1; j <= m; ++j) {
				val += map[i][j];
			}
			if (val < ans) ans = val;
		}
		if (val < ans) ans = val;
		return;
	}

	for (int i = 0; i < k; ++i) {
		if (flag & (1 << i)) continue;
		int tflag = flag;
		tflag |= (1 << i);
		seosun[depth+1] = i;
		makeseosun(depth + 1, tflag);
	}
}

int main(void) {
	ans = 1e9;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];

	for (int i = 0; i < k; ++i)
		cin >> rot[i][0] >> rot[i][1] >> rot[i][2];

	for (int i = 0; i < k; ++i) {
		seosun[0] = i;
		makeseosun(0, 1 << i);
	}
	cout << ans;
}