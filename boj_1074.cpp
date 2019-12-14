//boj 1074
#include <iostream>

using namespace std;

int n, r, c, cnt;

void findpos(int n, int y, int x) {
	if (n == 1) {
		if (y == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}
	findpos(n - 1, y, x);
	findpos(n - 1, y, x + (1 << (n - 1)));
	findpos(n - 1, y + (1 << (n - 1)), x);
	findpos(n - 1, y + (1 << (n - 1)), x + (1 << (n - 1)));
	return;
}


int main(void) {
	cin >> n >> r >> c;
	findpos(n, 0, 0);
}