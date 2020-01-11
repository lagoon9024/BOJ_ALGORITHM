// boj 2623
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
bool visit[1001];
int input[101][1000];
bool cycle;
vector<int> v[1001];
stack<int> stk;


void search(int num, vector<int> vec) {
	for (int i = 0; i < v[num].size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] == v[num][i]) {
				cycle = true;
				return;
			}
		}
		if (!visit[v[num][i]]) {
			vec.push_back(v[num][i]);
			visit[v[num][i]] = true;
			search(v[num][i], vec);
			vec.pop_back();
		}
	}
	stk.push(num);
}


int main(void) {
	cycle = false;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int len;
		int cur = 0;
		int next = 0;;
		cin >> len;
		for (int j = 0; j < len; j++) {
			cur = next;
			cin >> next;
			if (j > 0) {
				v[cur].push_back(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cycle) break;
		if (!visit[i]) {
			vector<int> cyclev;
			cyclev.push_back(i);
			visit[i] = true;
			search(i, cyclev);
			cyclev.pop_back();
		}
	}
	if (cycle) {
		cout << 0;
		return 0;
	}
	while (!stk.empty()) {
		cout << stk.top() << '\n';
		stk.pop();
	}
}