// boj 2056 ÀÛ¾÷
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, tasks[10001], d[10001];
vector<int> pretask[10001];

int dotask(int n) {
	int& ret = d[n];
	if (ret) return ret;
	if (pretask[n].empty()) return ret = tasks[n];
	for (int i = 0; i < pretask[n].size(); ++i) {
		ret = max(ret, dotask(pretask[n][i]) + tasks[n]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p, q;
		cin >> p >> q;
		tasks[i] = p;
		for (int j = 0; j < q; ++j) {
			int pre;
			cin >> pre;
			pretask[i].push_back(pre);
		}
	}
	int ans = 0;
	for (int i = n; i > 0; --i) {
		ans = max(ans, dotask(i));
	}
	cout << ans;
}