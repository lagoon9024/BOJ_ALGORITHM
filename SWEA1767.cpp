#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int r, c;
}pos;

int map[12][12];
int N;
int ans;
int chipmax;
vector<pos> v;
int flag;
//dir 0 up, 1 down, 2 left, 3 right

int makeline(int r, int c, int dir, int length) {
	switch(dir) {
	case 0:
		for (int i = 0; i < r; i++) {
			if (map[i][c] != 0) {
				flag = 1;
				return length;
			}
		}
		for (int i = 0; i < r; i++) {
			map[i][c] = 2;
			length++;
		}
		break;
	case 1:
		for (int i = N - 1; i > r; i--) {
			if (map[i][c] != 0) {
				flag = 1;
				return length;
			}
		}
		for (int i = N-1; i > r; i--) {
			map[i][c] = 2;
			length++;
		}
		break;
	case 2:
		for (int i = 0; i < c; i++) {
			if (map[r][i] != 0) {
				flag = 1;
				return length;
			}
		}
		for (int i = 0; i < c; i++) {
			map[r][i] = 2;
			length++;
		}
		break;
	case 3:
		for (int i = N-1; i > c; i--) {
			if (map[r][i] != 0) {
				flag = 1;
				return length;
			}
		}
		for (int i = N-1; i > c; i--) {
			map[r][i] = 2;
			length++;
		}
		break;
	}
	return length;
}

int deleteline(int r, int c, int dir, int length) {
	switch (dir) {
	case 0:
		for (int i = 0; i < r; i++) {
			map[i][c] = 0;
			length--;
		}
		break;
	case 1:
		for (int i = N - 1; i > r; i--) {
			map[i][c] = 0;
			length--;
		}
		break;
	case 2:
		for (int i = 0; i < c; i++) {
			map[r][i] = 0;
			length--;
		}
		break;
	case 3:
		for (int i = N - 1; i > c; i--) {
			map[r][i] = 0;
			length--;
		}
		break;
	}
	return length;
}

void dfs(int idx, int conncnt, int length) {
	if (idx == v.size()) {
		//cout << v.size() << '\n';
		if (conncnt > chipmax) {
			chipmax = conncnt;
			ans = 987654321;
		}
		if (chipmax == conncnt)
			if (length < ans) ans = length;
		return;
	}
	
	if (((int)v.size() - idx) < (chipmax - conncnt)) return;

	
	
	for (int i = 0; i < 4; i++) {
		flag = 0;
		length = makeline(v[idx].r, v[idx].c, i, length);
		if (flag == 1) dfs(idx + 1, conncnt, length);

		else{
			dfs(idx + 1, conncnt + 1, length);
			length = deleteline(v[idx].r, v[idx].c, i, length);
		}
	}	
}

int main (void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		v.clear();
		for (int i = 0; i < N; i++)
			fill_n(map[i], N, 0);
		ans = 987654321;
		chipmax = -99;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1 && i > 0 && i < N - 1 && j > 0 && j < N - 1) {
					v.push_back({ i,j });
				}
			}
		}
		dfs(0, 0, 0);
		cout << "#" << tc << " " << ans << '\n';
	}
}