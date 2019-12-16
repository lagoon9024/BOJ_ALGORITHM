// boj 2252
#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visit[32001];
vector<int> v[32001];

void search(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		if (!visit[v[num][i]]) {
			visit[v[num][i]] = true;
			search(v[num][i]);
		}
	}
	cout << num << " ";
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int stud, ent;
		cin >> stud >> ent;
		v[ent].push_back(stud);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			search(i);
		}
	}
}