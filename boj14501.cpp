//boj 14501

#include <iostream>

using namespace std;

int N, T, P;
int dp[20] = { 0 };

int main(void) {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		if (dp[i] > dp[i + 1])
			dp[i + 1] = dp[i];
		if (dp[i + T] < dp[i] + P)
			dp[i+T] = dp[i] + P;
	}
	cout << dp[N];
}