// swea 1808 지희의 고장난 계산기
// 결론 : 공학용 아니면 걍 새로사자
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, number[10], d[1000001];

int cnt(int num) {
	int ret = 0;
	while (num > 0) {
		int tmp = num % 10;
		if (!number[tmp]) return 1e9;
		else ++ret;
		num /= 10;
	}
	return ret;
}

int dp(int num) {
	int& ret = d[num];
	if (ret!=-1) return ret;
	ret = cnt(num);
	for (int i = 1; i <= sqrt(num); ++i) {
		if (!(num % i)) {
			int num1 = dp(num / i);
			int num2 = dp(i);
			ret = min(ret, num1 + num2 + 1);
		}
	}
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {		
		for (int i = 0; i < 10; ++i) {
			cin >> number[i];
			if (number[i])d[i] = 1;
		}
		cin >> n;
		fill_n(d, n+1, -1);
		int ans = dp(n) + 1;
		if (ans>=1e9) ans = -1;
		cout << '#' << tc << " " << ans << "\n";
	}
}