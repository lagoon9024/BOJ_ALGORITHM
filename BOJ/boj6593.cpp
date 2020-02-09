// boj 6593 »ó¹üºôµù
#include <iostream>
#include <queue>

using namespace std;

int L, R, C;
char building[30][30][30];
bool visit[30][30][30];
int dl[] = { -1,1,0,0,0,0 };
int dr[] = { 0,0,-1,1,0,0 };
int dc[] = { 0,0,0,0,-1,1 };
class pos {
public:
	int l, r, c, d;
	pos(int ll, int rr, int cc, int dd) {
		this->l = ll;
		this->r = rr;
		this->c = cc;
		this->d = dd;
	}
	bool onboard() {
		return l >= 0 && r >= 0 && c >= 0 && l < L && r < R && c < C;
	}
};

queue<pos> q;

void search() {
	while (!q.empty()) {
		int curl = q.front().l;
		int curr = q.front().r;
		int curc = q.front().c;
		int curd = q.front().d;
		q.pop();

		for (int i = 0; i < 6; ++i) {
			pos next(curl + dl[i], curr + dr[i], curc + dc[i], curd + 1);
			if (next.onboard() && !visit[next.l][next.r][next.c] && building[next.l][next.r][next.c] != '#') {
				if (building[next.l][next.r][next.c] == 'E') {
					cout << "Escaped in " << next.d << " minute(s).\n";
					return;
				}
				visit[next.l][next.r][next.c] = true;
				q.push(next);
			}
		}
	}
	cout << "Trapped!\n";
}

int main(void) {
	while (1) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		while (!q.empty())q.pop();
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				fill_n(visit[i][j], C, false);
				for (int k = 0; k < C; ++k) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						q.push(pos(i, j, k, 0));
						visit[i][j][k] = true;
					}
				}
			}
		}
		search();
	}	
}