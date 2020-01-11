//boj 14503
#include <iostream>
#include <queue>

using namespace std;

int floar[50][50];
bool visit[50][50];
int row, col;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct psd {
	int r, c, d;
};

psd cleaner;

int cleaning() {
	int ans = 1;
	queue<psd> q;
	q.push(cleaner);
	visit[cleaner.r][cleaner.c] = true;
	while (1) {
		bool bflag = false;
		psd tmp = q.front();
		q.pop();

		for (int i = 1; i <= 4; i++) {
			int nd = tmp.d - i;
			if (nd < 0) nd += 4;

			int nr = tmp.r + dr[nd];
			int nc = tmp.c + dc[nd];

			if (floar[nr][nc] == 1 || visit[nr][nc]) continue;
				visit[nr][nc] = true;
				ans++;
				q.push({ nr,nc,nd });
				bflag = true;
				break;			
		}

		if (!bflag) {
			if (floar[tmp.r - dr[tmp.d]][tmp.c - dc[tmp.d]] == 1) return ans;
			else {
				q.push({ tmp.r - dr[tmp.d],tmp.c - dc[tmp.d],tmp.d });
			}
		}

	}

}

void solve() {
	cout << cleaning() <<'\n';
}

int main(void) {
	cin >> row >> col >> cleaner.r >> cleaner.c >> cleaner.d;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> floar[i][j];
		}
	}
	solve();
}