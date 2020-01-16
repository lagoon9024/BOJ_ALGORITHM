// boj 2931 gas pipe
#include <iostream>

using namespace std;

int n, m, ansr, ansc;
char eu[26][26];
bool visit[26][26];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int bmask = 0;

bool boundarycheck(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

bool ispossible(char ch, int dir) {
	if (ch == '+') return true;
	else if (ch == '-' && (dir == 2 || dir == 3)) return true;
	else if (ch == '|' && (dir == 0 || dir == 1)) return true;
	else if (ch == '1' && (dir == 1 || dir == 3)) return true;
	else if (ch == '2' && (dir == 0 || dir == 3)) return true;
	else if (ch == '3' && (dir == 0 || dir == 2)) return true;
	else if (ch == '4' && (dir == 1 || dir == 2)) return true;
	else return false;
}

void pipe(int r, int c, int dir) {
	if (eu[r][c] == 'M' || eu[r][c] == 'Z') return;
	for (int i = 0; i < 4; ++i) {
		if (!ispossible(eu[r][c], i)) continue;
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (!boundarycheck(nr, nc) || visit[nr][nc]) continue;
		if (eu[nr][nc] == '.') {
			ansr = nr;
			ansc = nc;
			bmask |= 1 << i;
			continue;
		}
		visit[nr][nc] = true;
		pipe(nr, nc, i);
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> eu[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!visit[i][j] && eu[i][j] != '.' && eu[i][j] != 'Z' && eu[i][j] != 'M') {
				visit[i][j] = true;
				pipe(i, j, 0);

			}
		}
	}
	switch (bmask) {
	case 3:
		cout << ansr << " " << ansc << " " << '|';
		break;	
	case 5:
		cout << ansr << " " << ansc << " " << '1';
		break;
	case 6:
		cout << ansr << " " << ansc << " " << '2';
		break;
	case 9:
		cout << ansr << " " << ansc << " " << '4';
		break;
	case 10:
		cout << ansr << " " << ansc << " " << '3';
		break;
	case 12:
		cout << ansr << " " << ansc << " " << '-';
		break;
	case 15:
		cout << ansr << " " << ansc << " " << '+';
		break;
	default:
		break;
	}
}