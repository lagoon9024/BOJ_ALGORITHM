// boj 2629 ¾çÆÈÀú¿ï
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sinkers;
bool visit[31][15001];
int n, m;

void compare(int cnt, int weight) {
	if (visit[cnt][weight]) return;
	visit[cnt][weight] = true;
	if (cnt >= n) return;
	
	compare(cnt+1, weight + sinkers[cnt]);
	compare(cnt+1, weight);
	compare(cnt+1, abs(weight - sinkers[cnt]));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		sinkers.push_back(w);
	}

	compare(0, 0);
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int ball;
		cin >> ball;
		if (ball > 15000) cout << "N ";
		else if (visit[n][ball]) cout << "Y ";
		else cout << "N ";
	}
}