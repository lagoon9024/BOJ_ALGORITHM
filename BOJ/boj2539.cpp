// boj 2539 모자이크

 //색종이는 도화지 바닥에 붙여서 붙인다 ---- 가장 높이 찍힌 점보다 색종이는 커야한다
 //잘못 색칠된 부분을 벡터에 저장, 색종이의 커버리지로 덮어 필요 색종이의 수를 체크한다
 //색종이가 최대 1000000의 사이즈가 가능하므로 색종이 크기를 binary search로 접근하여 연산횟수를 최소화 시켜주었다
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