//boj 1436
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int idx = 1;
	int i = 1;
	while (idx <= n) {
		int tmp = i;
		while (tmp!=0) {
			if (tmp % 1000 == 666) {
				idx++;
				break;
			}
			tmp /= 10;			
		}
		i++;
	}
	cout << i - 1;
}