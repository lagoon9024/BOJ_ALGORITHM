//boj 9461
#include <iostream>
using namespace std;
long long d[101] = { 0,1,1,1,2,2,3,4,5,7,9,12, };
int main(void) {
	for (int i = 6; i <= 100; i++) {
		d[i] = d[i - 5] + d[i - 1];
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}