// boj 5557 1st grade
#include <iostream>

using namespace std;
int n;
int number[101];
long long d[101][21];

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> number[i];
	d[1][number[1]]++;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (d[i - 1][j]) {
				if (j + number[i] <= 20) d[i][j + number[i]] += d[i - 1][j];
				if (j - number[i] >= 0) d[i][j - number[i]] += d[i - 1][j];
			}
		}
	}
	cout << d[n-1][number[n]];
}
