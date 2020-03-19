// boj 2631 줄세우기
// LIS(Largest Increasing Subsequence) 문제
#include <iostream>

using namespace std;
int n, number[200], d[200];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> number[i];
	}
	for (int i = 0; i < n; ++i) {
		if (!d[i])d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (number[i] > number[j]) {
				if (d[i] < d[j] + 1) {
					d[i] = d[j] + 1;
				}
			}
		}
	}
	int maxl = 0;
	for (int i = 0; i < n; ++i)	maxl = maxl > d[i] ? maxl : d[i];

	cout << n - maxl;
}