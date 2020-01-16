//boj17140 2-dimension array computing
#include <iostream>
#include <vector>

using namespace std;

int R, C, k;
int map[101][101];
int rsize, csize;
int cnt[101];



void optR(int r) {
	fill_n(cnt, 101, 0);
	int idx = 1;
	while (idx <= 100) {
		if (map[r][idx]) ++cnt[map[r][idx]];
		++idx;
	}
	fill_n(map[r], 101, 0);
	vector<int> v[101];
	int tmpsize = 0;
	for (int i = 1; i <= 100; ++i) {
		if (cnt[i]) {
			v[cnt[i]].push_back(i);
			tmpsize += 2;
		}
	}
	if (csize < tmpsize)csize = tmpsize;
	idx = 1;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (idx > 99) return;
			map[r][idx] = v[i][j];
			map[r][idx + 1] = i;
			idx += 2;
		}
	}
}

void optC(int c) {
	fill_n(cnt, 101, 0);
	int idx = 1;
	while (idx <= 100) {
		if (map[idx][c]) ++cnt[map[idx][c]];
		++idx;

	}
	for (int i = 1; i <= 100; ++i) {
		map[i][c] = 0;
	}
	vector<int> v[101];
	int tmpsize = 0;
	for (int i = 1; i <= 100; ++i) {
		if (cnt[i]) {
			v[cnt[i]].push_back(i);
			tmpsize += 2;
		}
	}
	if (rsize < tmpsize) rsize = tmpsize;
	idx = 1;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (idx > 99) return;
			map[idx][c] = v[i][j];
			map[idx + 1][c] = i;
			idx += 2;
		}
	}
}

int main(void) {
	cin >> R >> C >> k;

	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> map[i][j];
	rsize = csize = 3;
	int ans = 0;

	while (map[R][C] != k) {

		if (rsize >= csize) {
			int tmp = rsize;
			csize = 0;
			for (int i = 1; i <= tmp; ++i) {
				optR(i);
			}
		}
		else {
			int tmp = csize;
			rsize = 0;
			for (int i = 1; i <= tmp; ++i) {
				optC(i);
			}
		}

		++ans;
		if (ans > 100) {
			cout << -1;
			return 0;
		}
	}

	cout << ans;
}