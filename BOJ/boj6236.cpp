// boj 6236 ¿ëµ·°ü¸®
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> dailymoney;

bool canlive(int val){
	int popday = 1, idx = 0, remain = 0;;
	while (popday <= m+1) {
		if (idx >= n) return true;
		if (remain >= dailymoney[idx]) {
			remain -= dailymoney[idx++];
		}
		else {
			remain = val - dailymoney[idx++];
			++popday;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int maxm = 0;
	for (int i = 0; i < n; ++i) {
		int money;
		cin >> money;
		dailymoney.push_back(money);
		maxm = maxm > money ? maxm : money;
	}
	int left = maxm, right = 1e9, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (canlive(mid)) right = mid;
		else left = mid + 1;
	}
	cout << left;
}