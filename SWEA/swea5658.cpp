// swea 5658 보물상자 비밀번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> pw;
vector<long long> nums;

bool desc(int a, int b) {
	return b<a;
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			char var;
			cin >> var;
			if (var >= '0' && var <= '9') var = var - '0';
			else {
				var = var - 'A' + 10;
			}
			pw.push_back(var);
		}
		for (int i = 0; i < n / 4; ++i) {
			for (int j = 0; j < n; j += n / 4) {
				long long val =0;
				for (int m = 0; m < n / 4; ++m) {
					int idx = i + j + m;
					if (idx >= n) idx -= n;
					val |= (pw[idx] << (((n/4)-1-m) * 4));
				}
				nums.push_back(val);
			}
		}
		sort(nums.begin(), nums.end(), desc);

		int v = 1;
		int ansidx = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != nums[i - 1]) ++v;
			if (v == k) {
				ansidx = i;
				break;
			}
		}
		cout << '#' << tc << " " << nums[ansidx] << '\n';
		nums.clear();
		pw.clear();
	}
}
