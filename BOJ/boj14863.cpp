// boj 14863 서울에서 경산까지
#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int wt[100], wa[100], bt[100], ba[100], d[101][100001];

int dp(int num, int t) {
	int& ret = d[num][t];
	if (ret != -1) return ret;
	if (num == n) return ret = 0;
	ret = -1e9;
	if (t >= wt[num]) ret = max(ret, dp(num + 1, t - wt[num]) + wa[num]);
	if (t >= bt[num]) ret = max(ret, dp(num + 1, t - bt[num]) + ba[num]);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < 101; ++i)
		fill_n(d[i], 100001, -1);
	for (int i = 0; i < n; ++i) {
		cin >> wt[i] >> wa[i] >> bt[i] >> ba[i];
	}
	int ans = dp(0, k);
	cout << (ans == -1 ? 0 : ans);
}