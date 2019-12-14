// boj 1328
// 가장 낮은 높이의 빌딩은 이전상태값을 기준으로 놓는 방식으로 접근한다.
#include <iostream>

using namespace std;

int n, l, r;

long long d[101][101][101] = { 0 };

int main(void) {
	cin >> n >> l >> r;
	d[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				d[i][j][k] = d[i - 1][j][k - 1] + d[i - 1][j - 1][k] + d[i - 1][j][k] * (i - 2);
				d[i][j][k] %= 1000000007;
			}
		}
	}
	cout << d[n][l][r];	
}