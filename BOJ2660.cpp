#include <iostream>
#include <queue>

using namespace std;

int N;
int member[51][51];
typedef struct {
	int mem, cnt;
}conn;

int main(void) {
	cin >> N;
	int x, y;
	for (;;) {
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		member[x][y] = member[y][x] = 1;
	}
	int chk[51];
	int cnt[51] = { 0 };
	queue<conn> q;
	for (int i = 1; i <= N; i++) {
		fill_n(chk, N + 1, 0);
		chk[i] = 1;
		for (int j = 1; j <= N; j++) {
			if (member[i][j] == 1 && chk[j]==0){
				chk[j] = 1;
				q.push({ j,1 });
			}
		}
		while (!q.empty()) {
			conn tmp = q.front();
			q.pop();
			for (int j = 1; j <= N; j++) {
				if (member[tmp.mem][j] == 1&& chk[j]==0){
						chk[j] = 1;
						q.push({ j,tmp.cnt + 1 });
					}
			}
			 
		}
	}
	int min = N+1;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] < min) min = cnt[i];
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == min) cnt[0]++;
	}
	cout << min << " " << cnt[0]<< '\n';
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == min) cout << i << " ";
	}

}