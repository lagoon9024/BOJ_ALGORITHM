// boj 5532 ¹æÇĞ¼÷Á¦
#include <iostream>

using namespace std;

int main(void) {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int day1 = a / c;
	if (a % c) ++day1;
	int day2 = b / d;
	if (b % d) ++day2;
	if (day1 > day2) cout << l - day1;
	else cout << l - day2;
}