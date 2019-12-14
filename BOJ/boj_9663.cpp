#include <iostream>

using namespace std;

int n, ans;
bool checklu[30];
bool checkru[30];
bool checkc[15];

void donqueen(int row) {
	if (row == n - 1) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (checklu[row - j + n - 1] || checkru[row + j] || checkc[j]) continue;
			flag = true;
		}
		if (flag) ans++;
		return;
	}

	for (int j = 0; j < n; j++) {

		if (checklu[row - j + n - 1] || checkru[row + j] || checkc[j]) continue;
		checklu[row - j + n - 1] = true;
		checkru[row + j] = true;
		checkc[j] = true;
		donqueen(row + 1);
		checklu[row - j + n - 1] = false;
		checkru[row + j] = false;
		checkc[j] = false;
	}
	return;
}


int main(void) {
	ans = 0;
	cin >> n;

	donqueen(0);

	cout << ans;
}