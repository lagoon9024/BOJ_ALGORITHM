#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	long long K;

	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		K--;
		int res = 0;
		while (K > 0) {
			if (K % 2 == 1) K = (K-1) / 2 ;
			else if (K % 4 == 0) {
				res = 0; 
				break;
			}
			else if (K % 4 == 2) {
				res = 1;
				break;
			}
		}
		printf("#%d %d\n", tc, res);
	}
}