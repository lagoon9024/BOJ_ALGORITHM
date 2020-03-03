//boj 2449 전구
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, light[200], d[200][200];

int go(int s, int e) {
	if (d[s][e] != 1e9) return d[s][e];
	int &ret = d[s][e];
	for (int i = s; i < e; ++i) {
		int change = 1;
		if (light[s] == light[i + 1]) change = 0;
		//s지점에서 i지점까지 같게만든 최소횟수 + i+1지점에서 e지점까지 같게만든 최소횟수
		//s~i까지 같게만든 상태를 전제로 하기때문에 change 횟수는 i+1과 비교하여 둘이 같은경우 0, 다른경우 1회로 저장
		ret = min(d[s][e], go(s, i) + go(i + 1, e) + change);
	}
	return ret;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fill_n(d[i], n, 1e9);
		cin >> light[i];
		d[i][i] = 0;
	}
	// 0~n-1까지 같게 만든 최소 횟수
	cout << go(0, n - 1);
}