// boj 11967 ºÒÄÑ±â
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int n, m;
vector<int> switches[10000];
bool visit[100][100], light[100][100];
class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int ur, uc, vr, vc;
		cin >> ur >> uc >> vr >> vc;
		--ur, --uc, --vr, --vc;
		switches[ur * 100 + uc].push_back(vr * 100 + vc);
	}
	
	queue<pos> q;
	q.push(pos(0, 0));
	light[0][0] = true;
	visit[0][0] = true;
	int ans = 1;

	while (!q.empty()) {
		bool flag = false;
		int curr = q.front().r;
		int curc = q.front().c;
		q.pop();
		int idx = curr * 100 + curc;
		for (int i = 0; i < switches[idx].size(); ++i) {
			int nr = switches[idx][i] / 100;
			int nc = switches[idx][i] % 100;
			if (!light[nr][nc]) {
				++ans;
				flag = true;
				light[nr][nc] = true;
			}
		}
		if (flag) memset(visit, 0, sizeof(visit));
		for (int d = 0; d < 4; ++d) {
			int nr = curr + dr[d];
			int nc = curc + dc[d];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || visit[nr][nc] || !light[nr][nc]) continue;
			visit[nr][nc] = true;
			q.push(pos(nr, nc));
		}		
	}
	cout << ans;
}