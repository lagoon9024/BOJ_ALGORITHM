// boj 1713 후보 추천하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int rec[101];

class candidate {
public:
	int order, num;
	candidate(int o, int n) {
		this->order = o;
		this->num = n;
	}
};

bool comp(candidate a, candidate b) {
	if (rec[a.num] == rec[b.num])
		return a.order > b.order;
	return rec[a.num] > rec[b.num];
}
bool ansc(candidate a, candidate b) {
	return a.num < b.num;
}

int main(void) {
	vector<candidate> v;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		bool ison = false;
		int num;
		cin >> num;
		if (rec[num]) ison = true;
		++rec[num];
		if (v.size() < n && !ison) v.push_back(candidate(i, num));
		else if (v.size() == n && !ison) {
			sort(v.begin(), v.end(), comp);
			int idx = v.back().num;
			v.pop_back();
			v.push_back(candidate(i, num));
			rec[idx] = 0;
		}
	}
	sort(v.begin(), v.end(), ansc);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].num << " ";
}