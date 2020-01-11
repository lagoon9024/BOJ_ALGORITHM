// boj1918 postfix
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

char str[101];
int len;

// priority 1 () 2 */ 3 +-
int priority(char c) {
	if (c == '+' || c == '-') return 0;
	else if (c == '*' || c == '/') return 1;
	else return -1;
}


void postview() {
	stack<char> s;

	for (int i = 0; i < len; ++i) {
		switch (str[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!s.empty() && (priority(str[i]) <= priority(s.top()))) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
			break;
		case '(':
			s.push(str[i]);
			break;
		case ')':
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			cout << str[i];
			break;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main(void) {
	cin >> str;
	len = strlen(str);

	postview();
}