//boj 2449 ����
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, light[200], d[200][200];

int go(int s, int e) {
	if (d[s][e] != 1e9) return d[s][e];
	int &ret = d[s][e];
	for (int i = s; i < e; ++i) {
		int change = 1;
		if (light[s] == light[i + 1]) change = 0;
		//s�������� i�������� ���Ը��� �ּ�Ƚ�� + i+1�������� e�������� ���Ը��� �ּ�Ƚ��
		//s~i���� ���Ը��� ���¸� ������ �ϱ⶧���� change Ƚ���� i+1�� ���Ͽ� ���� ������� 0, �ٸ���� 1ȸ�� ����
		ret = min(d[s][e], go(s, i) + go(i + 1, e) + change);
	}
	return ret;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fill_n(d[i], n, 1e9);
		cin >> light[i];
		d[i][i] = 0;
	}
	// 0~n-1���� ���� ���� �ּ� Ƚ��
	cout << go(0, n - 1);
}