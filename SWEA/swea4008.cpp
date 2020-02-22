// swea 4008 숫자 만들기
#include <iostream>
#include <vector>

using namespace std;

int n, oper[4], val[12];
int minval, maxval;
const int inf = 1e9;
const int minf = -1e9;

void calc(int plus, int minus, int mul, int div, int depth, int res) {
	if (!plus && !minus && !mul && !div) {
		if (res < minval) minval = res;
		if (res > maxval) maxval = res;
		return;
	}
	if (plus)
		calc(plus - 1, minus, mul, div, depth + 1, res + val[depth + 1]);
	if (minus)
		calc(plus, minus - 1, mul, div, depth + 1, res - val[depth + 1]);
	if (mul)
		calc(plus, minus, mul - 1, div, depth + 1, res * val[depth + 1]);
	if (div)
		calc(plus, minus, mul, div - 1, depth + 1, res / val[depth + 1]);
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		minval = inf;
		maxval = minf;
		for (int i = 0; i < 4; ++i)
			cin >> oper[i];
		for (int i = 0; i < n; ++i)
			cin >> val[i];
		calc(oper[0], oper[1], oper[2], oper[3], 0, val[0]);

		cout << '#' << tc << " " << maxval-minval << '\n';
	}
}