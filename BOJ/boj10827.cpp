// boj 10827 a^b
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Multiply(string& s1, string& s2) {
	string ret="0";
	for (int i = s2.size() - 1; i >= 0; --i) {
		string res(s1);
		int carry = 0;
		for (int j = s1.size() - 1; j >= 0; --j) {
			int tmp = carry;
			carry = 0;
			tmp+=(s2[i] - '0')* (s1[j] - '0');
			if (tmp >= 10) {
				carry = tmp / 10;
				tmp %= 10;
			}
			res[j] = tmp + '0';
		}
		if (carry > 0)
			res.insert(res.begin(), carry + '0');
		res += string(s2.size() - 1 - i, '0');
		
		string tmpret(max(ret.size(),res.size()),'0');
		int addcarry = 0;
		for (int p = 0; p < tmpret.size();++p) {
			int temp = addcarry;
			addcarry = 0;
			if (p < res.size())
				temp += res[res.size()-1-p] - '0';
			if (p < ret.size())
				temp += ret[ret.size()-1-p] - '0';
			if (temp >= 10) {
				addcarry = 1;
				temp -= 10;
			}
			tmpret[tmpret.size()-1-p] = temp+'0';
		}
		if (addcarry) {
			tmpret.insert(tmpret.begin(), '1');
		}
		ret = tmpret;
	}
	return ret;
}

string power(string& s1, int p) {
	if (p == 1)
		return s1;
	string ret = power(s1, p - 1);
	ret = Multiply(ret, s1);
	return ret;
}

int main(void) {
	string A;
	int B;
	cin >> A >> B;
	string::iterator finder = find(A.begin(), A.end(), '.');//std::find in <algorithm>
	int idx = 0;
	if (finder != A.end()) {
		idx = A.end() - 1 - finder;
		A.erase(finder);
	}

	idx *= B;

	string res = power(A, B);
	if (idx > 0)
		res.insert(res.end() - idx, '.');
	cout << res;	
}