// boj 3430 용이산다
#include <iostream>
#include <set>

using namespace std;
int n, m;
const int len = 1e6;
int rain[len], start[len];
bool printidx[len];
set<int> sun;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		bool flag = false;
		cin >> n >> m;
		fill_n(rain, m, 0);
		fill_n(printidx, m, false);
		fill_n(start, m, 0);
		sun.clear();
		for (int i = 0; i < m; ++i) {
			int val;
			cin >> val;
			if (flag) continue;
			if (val > 0) {
				set<int>::iterator finder = sun.lower_bound(start[val - 1]);
				if (finder == sun.end()) {
					flag = true;
					continue;
				}
				rain[*finder] = val;
				sun.erase(finder);

				start[val - 1] = i + 1;
				printidx[i] = true;
			}
			else sun.insert(i);
		}
		if (!flag) {
			cout << "YES\n";
			for (int i = 0; i < m; ++i) {
				if (!printidx[i]) cout << rain[i] << " ";
			}
			cout << '\n';
		}
		else cout << "NO\n";
	}
}