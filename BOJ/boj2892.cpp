#include <iostream>
#include <string>

using namespace std;
int n;
int main(void) {
	cin >> n;
	string pass;
	for (int i = 0; i < n; ++i) {
		cin >> pass;
		int decrypted = 0;
		for (int j = 0; j < pass.length(); ++j) {
			int tmp;
			if (pass[j] - 'a' >= 0) tmp = pass[j] - 'a' + 10;
			else tmp = pass[j] - '0';
			decrypted |= tmp << (4 * (pass.length() - 1 - j));
		}
		bool flag = false;
		for (int k = 0; k < 10; ++k) {
			if (flag) break;
			char pkey = k + '0';
			if ((decrypted ^ pkey) - 'a' >= 0) flag = true;
		}
		if (flag) cout << '-';
		else cout << '.';
	}
}