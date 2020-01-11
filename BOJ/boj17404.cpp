// boj 17404 RGB distance 2
#include <iostream>

using namespace std;

int n, r, g, b;
int red[1005][5], blue[1005][5], green[1005][5];

int MIN(int x, int y) {
	if (x < y) return x;
	return y;
}

int main(void) {
	cin >> n;
	
	for (int j = 1; j < 5; j <<= 1) 
		red[0][j] = blue[0][j] = green[0][j] = 1000001;

	cin >> red[0][1] >> green[0][2] >> blue[0][4];
	for (int i = 1; i < n; ++i) {
		cin >> r >> g >> b;
		for (int j = 1; j < 5; j <<= 1) {
			red[i][j] = blue[i][j] = green[i][j] = 1000001;
			blue[i][j] = MIN(red[i - 1][j] + b, green[i - 1][j] + b);
			green[i][j] = MIN(blue[i - 1][j] + g, red[i - 1][j] + g);
			red[i][j] = MIN(blue[i - 1][j] + r, green[i - 1][j] + r);
		}
	}

	int ans = 987654321;
	for (int i = 1; i < 5; i <<= 1) {
		if(i&1)
			ans = MIN(ans, MIN(blue[n - 1][i], green[n - 1][i]));
		else if (i & (1 << 1))
			ans = MIN(ans, MIN(blue[n - 1][i], red[n - 1][i]));
		else
			ans = MIN(ans, MIN(green[n - 1][i], red[n - 1][i]));
		
	}

	cout << ans;
}
