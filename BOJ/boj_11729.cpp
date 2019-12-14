#include<iostream>
using namespace std;

void hanoi(int n, int now, int target, int sub) {
	if (n != 0) {
		hanoi(n - 1, now, sub, target);
		cout << now << " " << target <<'\n';
		hanoi(n - 1, sub, target, now);
	}
}

int main(void) {
	int n;
	cin >> n;

	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 3, 2);
}