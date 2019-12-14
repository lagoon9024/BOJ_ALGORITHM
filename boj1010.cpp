//boj 1010
#include <iostream>
using namespace std;
int d[31][31] = { 0 };
int main(void) {
	for (int i = 1; i <= 30; i++) {
		d[i][i] = 1;
		d[1][i] = i;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			if (i == j) continue;
			d[i][j] = d[i-1][j - 1] + d[i][j-1];
		}
	}

	int n, m, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << d[n][m] << '\n';
	}
}