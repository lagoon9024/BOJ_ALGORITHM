// boj 16768 mooyo mooyo
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char mooyo[101][11];
bool visited[101][11];
bool moremerge=true;
int n, k;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct pos {
	int r, c;
};

bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < 10;
}

void mergemooyo() {
	queue<char> val;
	for (int i = 0; i < 10; ++i) {
		int idx = n-1;
		while (idx>=0) {
			if (mooyo[idx][i] != '0') val.push(mooyo[idx][i]);
			--idx;
		}
		idx = n-1;
		while (!val.empty()) {
			mooyo[idx][i] = val.front();
			val.pop();
			--idx;
		}
		while (idx >= 0) {
			mooyo[idx][i] = '0';
			--idx;
		}
	}
}

void breakmooyo(int r, int c, char val) {
	vector<pos> v;
	queue<pos> q;
	q.push({ r,c });
	visited[r][c] = true;
	v.push_back({ r,c });

	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];
			if (visited[nr][nc] || !check(nr, nc) || mooyo[nr][nc] != val) continue;
			visited[nr][nc] = true;
			v.push_back({ nr,nc });
			q.push({ nr, nc });
		}
	}

	if (v.size() < k) {
		v.clear();
	}
	else {
		moremerge = true;
		while (!v.empty()) {
			pos tmp = v.back();
			mooyo[tmp.r][tmp.c] = '0';
			v.pop_back();
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> mooyo[i][j];
		}
	}

	while (moremerge) {
		moremerge = false;

		for (int i = 0; i < n; ++i)
			fill_n(visited[i], 10, false);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (mooyo[i][j] == '0' || visited[i][j]) continue;
				breakmooyo(i, j, mooyo[i][j]);
			}
		}
		if (moremerge)
			mergemooyo();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << mooyo[i][j];
		}
		cout << '\n';
	}
}