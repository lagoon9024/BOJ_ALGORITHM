// boj 8986 ������
#include <iostream>
#include <algorithm>

using namespace std;
int position[100000], n;

long long dist(long long x) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		// ����� long long ������ ������������ integer�� �Ѿ�� overflow�� �߻��ϹǷ� x�� long long ���� ����
		ret += abs(x * i - position[i]);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> position[i];
	}
	int left = position[0];
	int right = position[n - 1];

	while (right - left > 3) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if (dist(mid1) < dist(mid2)) right = mid2;
		else left = mid1;
	}
	long long ans = dist(right);
	for (int i = left; i < right; ++i)
		ans = min(ans, dist(i));
	cout << ans;
}