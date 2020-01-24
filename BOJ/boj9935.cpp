// boj 9935 string explosion
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;

	stack<char> exp;
	stack<char> cache;
	vector<char> ans;
	int idx, subidx;
	int len = s1.length();
	int len2 = s2.length();
	for (int i = 0; i < len; ++i) {
		if (s1[i] == s2[0]) {
			idx = i;
			subidx = 0;
			while (idx<len &&(s1[idx] == s2[subidx] || s1[idx] == s2[0])) {
				if (s1[idx] == s2[0]) subidx = 0;
				exp.push(s1[idx]);
				++idx;
				++subidx;
				int tmplen = len2;
				
				if (exp.top()==s2.back()) {					
					while (tmplen) {					
						exp.pop();
						--tmplen;
					}
					if (!exp.empty()) {
						for (int j = 0; j < len2; ++j) {
							if (s2[j] == exp.top()) subidx = j + 1;
						}
					}
				}
			}
			while (!exp.empty()) {
				cache.push(exp.top());
				exp.pop();
			}
			while (!cache.empty()) {
				ans.push_back(cache.top());
				cache.pop();
			}
			i = idx-1;
		}
		else
			ans.push_back(s1[i]);
	}
	if (ans.empty()) cout << "FRULA";
	else {
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i];
	}
}