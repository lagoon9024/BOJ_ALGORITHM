// boj 16986 인싸들의 가위바위보
#include <iostream>

using namespace std;
int n, k;
int vs[10][10];
int	Round[3], score[3], km[3][20];
int used;

void go(int w, int c) {
	if (score[0] == k) {
		cout << 1;
		exit(0);
	}
	if (score[1] == k || score[2] == k) return;
	if (used == ((1 << n) - 1)) return;
	if (c < w) {
		int tmp=c;
		c = w;
		w = tmp;
	}
	if (!w) {
		for (int i = 1; i <= n; ++i) {
			if (used & (1 << (i - 1))) continue;
			used |= (1 << (i - 1));
			if (vs[i][km[c][Round[c]]] == 2) {
				++Round[c];
				++score[w];
				go(w, 3 - c - w);
				--Round[c];
				--score[w];
			}
			else {
				++Round[c];
				++score[c];
				go(c, 3 - c - w);
				--Round[c];
				--score[c];
			}
			used ^= (1 << (i - 1));
		}
	}
	else {
		if (vs[km[w][Round[w]]][km[c][Round[c]]] == 2) {
			++Round[w];
			++Round[c];
			++score[w];
			go(w, 3 - c - w);
			--Round[w];
			--Round[c];
			--score[w];
		}
		else {
			++Round[w];
			++Round[c];
			++score[c];
			go(c, 3 - c - w);
			--Round[w];
			--Round[c];
			--score[c];
		}
	}
}

int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> vs[i][j];
		}
	}
	for (int i = 1; i < 3; ++i) {
		for (int j = 0; j < 20; ++j) {
			cin >> km[i][j];
		}
	}
	go(0, 1);
	cout << 0;
}