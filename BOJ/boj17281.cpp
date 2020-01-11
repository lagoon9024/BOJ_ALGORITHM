// boj 17281
#include <iostream>
#include <vector>

using namespace std;

int inning;
int result[51][10];
int ans = 0;
vector<int> hitter;
bool chkhitter[10];


void play() {
	int score = 0;
	int num = 1;
	for (int inn = 1; inn <= inning; inn++) {
		int base = 0;
		int outcnt = 0;
		while (outcnt < 3) {
			int hit = result[inn][hitter[num]];
			if (hit == 0) outcnt++;
			else {
				base += 1;
				for (int h = 1; h <= hit; h++) {
					base <<= 1;
					if ((1 << 4) & base) {
						base &= ~(1 << 4);
						score++;
					}
				}
			}
			num++;
			if (num == 10) num = 1;
		}
	}
	if (ans < score) ans = score;
}

void makecomplex(int depth) {
	if (depth > 9) {
		play();
		return;
	}

	if (depth == 4) {
		hitter.push_back(1);
		makecomplex(depth + 1);
		hitter.pop_back();
	}
	else {
		for (int idx = 2; idx <= 9; idx++) {
			if (chkhitter[idx]) continue;
			hitter.push_back(idx);
			chkhitter[idx] = true;
			makecomplex(depth + 1);
			hitter.pop_back();
			chkhitter[idx] = false;
		}
	}
}

void solve() {
	hitter.push_back(-1);
	makecomplex(1);
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> inning;
	for (int i = 1; i <= inning; i++)
		for (int j = 1; j <= 9; j++)
			cin >> result[i][j];
	solve();
}