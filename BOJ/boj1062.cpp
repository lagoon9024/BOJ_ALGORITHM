#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool learned[26];
int n, k, ans;
vector<string> v;
void permutate(int start, int depth) {
	if (ans == n) return;
	if (depth == k - 5) {
		int tmpans = 0;
		for (int i = 0; i < v.size(); ++i) {
			int len = v[i].length();
			if (!len) ++tmpans;
			for (int j = 0; j < len; ++j) {
				if (!learned[v[i][j] - 'a']) break;
				if (j == len - 1) ++tmpans;
			}
		}
		ans = ans > tmpans ? ans : tmpans;
		return;
	}
	for (int i = start; i < 26; ++i) {
		if (learned[i])continue;
		learned[i] = true;
		permutate(i + 1, depth + 1);
		learned[i] = false;
	}
}
int main(void) {
	cin >> n >> k;
	string s;
	ans = 0;
	learned['a' - 'a'] = learned['n' - 'a'] = learned['t' - 'a'] = learned['i' - 'a'] = learned['c' - 'a'] = true;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		s = s.substr(4, s.length());
		for (int j = 0; j < 4; ++j) s.pop_back();
		v.push_back(s);
	}
	if (k == 26) ans = n;
	else if (k >= 5) permutate(0, 0);
	cout << ans;
}