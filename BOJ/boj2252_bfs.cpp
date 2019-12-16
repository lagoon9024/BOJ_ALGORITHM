//boj 2252
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt;

vector<int> v[32001];
vector<int> u[32001];
int degree[32001];

void search() {
	int cnt = n;
	while (cnt > 0) {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) {
				q.push(i);
				degree[i] = -1;
			}
		}
		while (!q.empty()) {
			int tmp = q.front();
			cout << tmp << " ";
			cnt--;
			q.pop();
			for (int i = 0; i < u[tmp].size(); i++) {
				if (degree[u[tmp][i]] < 0) continue;
				
				degree[u[tmp][i]]--;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	cnt = 0;
	for (int i = 0; i < m; i++) {
		int stud, ent;
		cin >> stud >> ent;
		v[ent].push_back(stud);
		u[stud].push_back(ent);
	}
	for (int i = 1; i <= n; i++) {
		degree[i] = v[i].size();

	}

	search();
}