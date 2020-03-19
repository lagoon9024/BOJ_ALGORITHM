// boj 2539 ������ũ

 //�����̴� ��ȭ�� �ٴڿ� �ٿ��� ���δ� ---- ���� ���� ���� ������ �����̴� Ŀ���Ѵ�
 //�߸� ��ĥ�� �κ��� ���Ϳ� ����, �������� Ŀ�������� ���� �ʿ� �������� ���� üũ�Ѵ�
 //�����̰� �ִ� 1000000�� ����� �����ϹǷ� ������ ũ�⸦ binary search�� �����Ͽ� ����Ƚ���� �ּ�ȭ �����־���
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, maxp, wcol, minc=1e9, maxh=0;
vector<int> wrongpt;

int paper(int width) {
	int ret = 1;
	int prev = wrongpt[0];
	for (int i = 0; i < wrongpt.size(); ++i) {
		if (wrongpt[i] >= prev + width) {
			prev = wrongpt[i];
			++ret;
		}
	}
	return ret;
}

int main(void) {
	cin >> n >> m >> maxp >> wcol;
	for (int i = 0; i < wcol; ++i) {
		int p, q;
		cin >> p >> q;
		wrongpt.push_back(q);
		if (p > maxh) maxh = p;
		if (q < minc) minc = q;	
	}
	sort(wrongpt.begin(), wrongpt.end());
	int left = maxh;
	int right = 1e6;

	while (left < right) {
		int mid = (left + right) / 2;
		if (paper(mid) <= maxp) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
}