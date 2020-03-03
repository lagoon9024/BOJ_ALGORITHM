//swea 1247 최적경로
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, path[12][12], d[11][1 << 11];
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
vector<pos> points;

int dp(int cur, int _bit) {
	int& ret = d[cur][_bit];
	int maxbit = (1 << (n + 1)) - 1;
	if (ret != -1) return ret;
	if (_bit == maxbit) return path[cur][n + 1];
	ret = 1e9;
	for (int i = 1; i <= n; ++i) {
		if (_bit & (1 << i)) continue;
		ret = min(ret, dp(i, (_bit | (1 << i))) + path[cur][i]);
	}
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		for (int i = 0; i < 11; ++i) fill_n(d[i], 1 << 11, -1);
		points.clear();
		cin >> n;
		int str, stc, edr, edc;
		cin >> str >> stc >> edr >> edc;
		points.push_back(pos(str, stc));
		for (int i = 0; i < n; ++i) {
			int r, c;
			cin >> r >> c;
			points.push_back(pos(r, c));
		}
		points.push_back(pos(edr, edc));
		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < n + 2; ++j) {
				path[i][j] = abs(points[i].r - points[j].r) + abs(points[i].c - points[j].c);
			}
		}

		cout << '#' << tc << " " << dp(0, 1) << '\n';
	}
}