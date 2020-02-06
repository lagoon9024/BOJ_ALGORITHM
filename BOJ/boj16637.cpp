// boj 16637 괄호추가하기
#include <iostream>
#include <vector>

using namespace std;

vector<char> oper;
vector<int> num;
long long ans = (1e9) * (-1);

long long calc(char op, long long a, long long b) {
	switch (op) {
	case '*':
		return a * b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	}
}

void sol(long long res, int idx) {
	if (idx >= oper.size()) {
		if (ans < res)
			ans = res;
		return;
	}
	long long next = calc(oper[idx], res, num[idx + 1]);
	sol(next, idx + 1);
	if (idx + 1 < oper.size()) {
		next = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
		sol(calc(oper[idx], res, next), idx + 2);
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char var;
		cin >> var;
		if (var >= '0' && var <= '9')
			num.push_back(var - '0');
		else
			oper.push_back(var);
	}
	sol(num[0], 0);
	cout << ans;
}