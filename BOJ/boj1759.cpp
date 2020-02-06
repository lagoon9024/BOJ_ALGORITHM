// boj 1759 암호만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<char> v;
vector<char> ans;
bool check(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

void next(int idx, int depth, int mo, int za) {
	if (depth == n) {
		if (mo >= 1 && za >= 2) {
			for (int i = 0; i < ans.size(); ++i)
				cout << ans[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx + 1; i < v.size(); ++i) {
		ans.push_back(v[i]);
		if (check(v[i]))
			next(i, depth+1, mo+1, za);
		else
			next(i, depth+1, mo, za+1);
		ans.pop_back();
	}
}

int main(void) {	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		ans.push_back(v[i]);
		if (check(v[i]))
			next(i, 1, 1, 0);
		else
			next(i, 1, 0, 1);
		ans.pop_back();
	}
}