// boj 10711 ¸ð·¡¼º
#include <iostream>
#include <queue>

using namespace std;
int h, w;
int map[1001][1001], visit[1001][1001];

int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };

class pos {
public:
	int r, c;
	pos(int rr, int cc) {
		this->r = rr;
		this->c = cc;
	}
};
queue<pos> q;
bool isbroke(int r, int c, int val) {
	if (!val) return false;
	int adjcnt = 0;
	for (int d = 0; d < 8; ++d) {
		int adjr = r + dr[d];
		int adjc = c + dc[d];
		if (!map[adjr][adjc]) ++adjcnt;
		if (adjcnt >= val) return true;
	}
	return false;
}

int main(void) {
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c;
			cin >> c;
			if (c == '.') map[i][j] = 0;
			else map[i][j] = c - '0';
			if (map[i][j] && map[i][j] < 9) q.push(pos(i,j));
		}
	}

	int loop = 1;
	vector<pos> delpos;

	while(!q.empty()){
		int sz = q.size();
		while (sz--) {
			int cr = q.front().r;
			int cc = q.front().c;
			q.pop();
			if (isbroke(cr, cc, map[cr][cc])) delpos.push_back(pos(cr, cc));
		}
		
		for (int i = 0; i < delpos.size(); ++i) {
			for (int d = 0; d < 8; ++d) {				
				int nr = delpos[i].r + dr[d];
				int nc = delpos[i].c + dc[d];
				if (map[nr][nc] && map[nr][nc] < 9 && visit[nr][nc] != loop) {
					visit[nr][nc] = loop;
					q.push(pos(nr, nc));
				}
			}
		}
		if (delpos.empty()) break;
		while (!delpos.empty()) {
			int rr = delpos.back().r;
			int cc = delpos.back().c;
			map[rr][cc] = 0;
			delpos.pop_back();
		}
		++loop;
	}	
	cout << loop-1;
}