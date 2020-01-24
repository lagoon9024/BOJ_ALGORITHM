// boj 2044 windows
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char window[102][102];
char cascade[102][102];
int n, m;

struct pos {
	string str;
	int lenc, lenr, chstart;
};

vector<pos> windows;

bool compare(pos a, pos b) {
	return a.str < b.str;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	char tmpstr[12];

	for (int i = 1; i <= n; ++i) {
		fill_n(cascade[i], m + 1, '.');
		for (int j = 1; j <= m; ++j)
			cin >> window[i][j];
	}

	int vertex;
	for (int i = 1; i <= n; ++i) {		
		for (int j = 1; j <= m; ++j) {
			vertex = 0;
			int tmpc;
			if (window[i][j] == '+') {
				++vertex;
				int startj = j;
				window[i][j] = '.';
				int idx = 0;
				while (window[i][j] != '+') {
					++j;
					++vertex;
					if (window[i][j] >= 'a' && window[i][j] <= 'z') {
						if (idx==0) tmpc = j;
						tmpstr[idx] = window[i][j];
						idx++;
					}
				}
				tmpstr[idx] = '\0';

				window[i][j] = '.';
				int r = i+1;
				while (window[r][j] != '+') {
					++r;
				}
				window[r][j] = '.';
				window[r][startj] = '.';
				windows.push_back({ tmpstr,vertex,r-i,tmpc-startj });
				fill_n(tmpstr, 12, NULL);
			}
		}
	}

	sort(windows.begin(), windows.end(), compare);
	int ridx, cidx;
	ridx = cidx = 1;
	int lastr, lastc;

	for (int i = 0; i < windows.size(); ++i) {
		int clen = windows[i].lenc;
		int rlen = windows[i].lenr;
		int chst = windows[i].chstart;

		for (int r = ridx + 1; r < ridx + rlen; ++r) 
			cascade[r][cidx] = cascade[r][cidx+clen-1]='|';
		for (int c = cidx + 1; c < cidx + clen-1; ++c)
			cascade[ridx][c] = cascade[ridx + rlen][c] = '-';

		cascade[ridx][cidx + chst - 1] = cascade[ridx][cidx + chst + windows[i].str.size()] = '|';
		for (int l = 0; l < windows[i].str.size(); ++l) {
			cascade[ridx][cidx + chst + l] = windows[i].str[l];
		}
		cascade[ridx][cidx] = cascade[ridx][cidx + clen-1] = cascade[ridx + rlen][cidx] = cascade[ridx + rlen][cidx + clen-1] = '+';
		lastr = ridx + rlen - 1;
		lastc = cidx + clen - 2;
		++ridx;
		++cidx;
		for (int i = ridx; i <= lastr; ++i) {
			for (int j = cidx; j <= lastc; ++j) {
				if (cascade[i][j] == '.') continue;
				cascade[i][j] = '.';
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << cascade[i][j];
		}
		cout << '\n';
	}
	
}