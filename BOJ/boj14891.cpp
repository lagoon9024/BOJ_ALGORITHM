// boj 14891 Åé´Ï¹ÙÄû
#include <iostream>

using namespace std;

int gear[4][8];
int top[4];

int check(int val) {
	if (val >= 8)
		while (val >= 8) {
			val -= 8;
		}
	else if (val < 0)
		while (val < 0) {
			val += 8;
		}
	return val;
}

int main(void) {
	string s;
	int k;
	int rotate[4];
	for (int i = 0; i < 4; ++i) {
		cin >> s;
		for (int j = 0; j < 8; ++j) {
			gear[i][j] = s[j] - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int idx, dir;
		cin >> idx >> dir;
		--idx;
		fill_n(rotate, 4, 0);
		rotate[idx] = dir;
		int cur = idx;
		int prev = idx - 1;
		int ndir = (-1) * dir;
		while (cur > 0) {
			int adjc = check(top[cur] + 6);
			int adjp = check(top[prev] + 2);
			if (gear[cur][adjc] != gear[prev][adjp]) rotate[prev] = ndir;
			else break;
			cur = prev;
			--prev;
			ndir = ndir * (-1);
		}
		cur = idx;
		int next = idx + 1;
		ndir = dir * (-1);
		while (next < 4) {
			int adjc = check(top[cur] + 2);
			int adjn = check(top[next] + 6);
			if (gear[cur][adjc] != gear[next][adjn]) rotate[next] = ndir;
			else break;
			cur=next;
			++next;
			ndir = ndir * (-1);
		}
		for (int j = 0; j < 4; ++j) {
			top[j] -= rotate[j];
		}
	}

	int ans = 0;

	for (int i = 0; i < 4; ++i) {
		if (gear[i][check(top[i])])
			ans += (1 << i);
	}
	cout << ans;
}