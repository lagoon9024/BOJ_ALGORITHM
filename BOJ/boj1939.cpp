// boj 4179 บา!
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};

char map[1001][1001];
int r, c;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<pos> jih;
queue<pos> fire;
bool visit[1000][1000];
bool check(int rr, int cc) {
	return rr >= 0 && cc >= 0 && rr < r && cc < c;
}


int main(void) {
	ifstream fin("text.txt");
	/*ios::sync_with_stdio(false);
	fin.tie(nullptr);
	//ios::sync_with_stdio(false);
	//fin.tie(nullptr);*/
	fin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			fin >> map[i][j];
			if (map[i][j] == 'J') {
				jih.push(pos(i, j));
				visit[i][j] = true;
			}
			else if (map[i][j] == 'F') {
				visit[i][j] = true;
				fire.push(pos(i, j));
			}
		}
	}
	
	int cnt = 0;
	while (!jih.empty()) {
		++cnt;
		int size = fire.size();
		while (size--) {
			pos tmp = fire.front();
			fire.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];

				if (visit[nr][nc] || !check(nr, nc) || map[nr][nc] == '#') continue;
				visit[nr][nc] = true;
				fire.push(pos(nr, nc));
			}
		}
		size = jih.size();
		while (size--) {
			pos tmp = jih.front();
			jih.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = tmp.r + dr[i];
				int nc = tmp.c + dc[i];
				if (visit[nr][nc] || map[nr][nc] == '#') continue;
				if (nr < 0 || nc < 0 || nr > r - 1 || nc > c - 1) {
					cout << cnt;
					return 0;
				}
				if (nr == 0 || nc == 0 || nr == r - 1 || nc == c - 1) {
					cout << cnt + 1;
					return 0;
				}
				visit[nr][nc] = true;
				jih.push(pos(nr, nc));
			}
		}
	}
	cout << "IMPOSSIBLE";
}	