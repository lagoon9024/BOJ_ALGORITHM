#include <iostream>

using namespace std;

int main(void) {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		// N step total count
		int right = N * N;
		int left = (N - 1) * (N - 1) + 1;
		printf("#%d %d %d\n", i,left * 2 - 1, right * 2 - 1);
	}
}