//boj 17825
#include <iostream>

using namespace std;
int route[4][24] = {
	{ 0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, },
	{ 0, 2, 4, 6, 8 ,10, 12 ,14 ,16, 18, 20, 22, 24, 25, 30, 35, 40, },
	{ 0, 2, 4, 6, 8 ,10, 12 ,14 ,16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, },
	{ 0, 2, 4, 6, 8 ,10, 12 ,14 ,16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, }
};
int dice[10];
int horse[4][2] = { 0, };
int max = 0;

bool horseon(int curpt, int routenum, int horsenum) {
	for (int i = 0; i < 4; i++) {
		if (i == horsenum) continue;
		if (horse[i][0] == curpt && routenum == horse[i][1]) return false;
		
		if (route[horse[i][1]][horse[i][0]] == route[routenum][curpt]) {
			switch (route[routenum][curpt]) {
			case 16:
				if ((routenum == 0 && horse[i][1] > 0) || (routenum > 0 && horse[i][1] == 0)) break;
				if (routenum > 0 && horse[i][1] > 0 && horse[i][0] == curpt) return false;
			case 22:
				if ((routenum == 1 && horse[i][1] > 1) || (routenum > 1 && horse[i][1] == 1)) break;
				if (routenum > 1 && horse[i][1] > 1 && horse[i][0] == curpt) return false;
			case 24:
				if ((routenum == 1 && horse[i][1] > 1) || (routenum > 1 && horse[i][1] == 1)) break;
				if (routenum > 1 && horse[i][1] > 1 && horse[i][0] == curpt) return false;
			case 26:
				if ((routenum == 2 && curpt == 18) || (horse[i][1] == 2 && horse[i][0] == 18)) break;
				else return false;
			case 28:
				if ((routenum == 2 && curpt == 16) || (horse[i][1] == 2 && horse[i][0] == 16)) break;
				else return false;
			case 30:
				if (((routenum == 2 || routenum == 3) && curpt == 15) && ((horse[i][1] == 2 || horse[i][1] == 3) && horse[i][0] == 15)) return false;
				else if (curpt != 15 && horse[i][0] != 15) return false;
				else break;
			default:
				return false;
			}
		}
	}
	return true;
}

void go(int depth, int score) {
	if (depth == 10) {
		if (score > max) max = score;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (horse[i][0] == -1) continue;
		int nowpt = horse[i][0];
		int nowroute = horse[i][1];
		horse[i][0] = horse[i][0] + dice[depth];
		if (route[horse[i][1]][horse[i][0]] == 10) horse[i][1] = 0;
		else if (route[horse[i][1]][horse[i][0]] == 20) horse[i][1] = 1;
		else if (route[horse[i][1]][horse[i][0]] == 30 && horse[i][0] == 15) horse[i][1] = 2;

		if ((horse[i][0] != 0 && route[horse[i][1]][horse[i][0]] == 0)||horse[i][0]>23) {
			horse[i][0] = -1;
			go(depth + 1, score);
		}
		else if (horseon(horse[i][0], horse[i][1], i)) {
			go(depth + 1, score + route[horse[i][1]][horse[i][0]]);
		}
		horse[i][0] = nowpt;
		horse[i][1] = nowroute;
	}
}

void solve() {
	for (int i = 0; i < 4; i++) horse[i][1] = 3;
	go(0, 0);
	cout << max;
}

int main(void) {
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	solve();
}