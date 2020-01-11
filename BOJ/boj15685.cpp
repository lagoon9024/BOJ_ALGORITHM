// boj 15685

#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int num;

struct dcurve{
	int r, c, d, g;
};
struct pos{
	int r, c;
};
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };

int prvdsize;
dcurve dragon[20];
vector<pos> dcurvept;

int findsquare(int r, int c) {
	if (map[r + 1][c] == 1 && map[r][c + 1] == 1 && map[r + 1][c + 1] == 1)
		return 1;
	else
		return 0;
}

void nextgen() {
	int dsize = dcurvept.size();
	int stdr = dcurvept[prvdsize].r;
	int stdc = dcurvept[prvdsize].c;
	prvdsize = dsize;
	for (int i = 0; i <prvdsize; i++) {
		int prvr = dcurvept[i].r-stdr;
		int prvc = dcurvept[i].c-stdc;
		int tmp = prvr;
		prvr = prvc+stdr;
		prvc = tmp*(-1)+stdc;
		dcurvept.push_back({ prvr,prvc });
		map[prvr][prvc] = 1;
	}
}


void makecurve(int idx) {	
	for (int gen = 0; gen <= dragon[idx].g; gen++) {
		if (gen == 0) {
			dcurvept.push_back({ dragon[idx].r,dragon[idx].c });
			dcurvept.push_back({ dragon[idx].r + dr[dragon[idx].d],dragon[idx].c + dc[dragon[idx].d] });
			map[dcurvept[0].r][dcurvept[0].c]=1;
			map[dcurvept[1].r][dcurvept[1].c]=1;
			prvdsize = 1;
		}
		else
			nextgen();
	}
}

void solve() {
	for (int i = 0; i < num; i++) {
		dcurvept.clear();
		makecurve(i);
	}
	int ans = 0;


	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if(map[i][j]==1)
				ans += findsquare(i, j);
		}
	}
	cout << ans;
}

int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> dragon[i].c >> dragon[i].r >> dragon[i].d >> dragon[i].g;
	}
	solve();
}