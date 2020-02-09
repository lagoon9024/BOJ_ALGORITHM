// boj 5014 스타트링크
#include <iostream>
#include <algorithm>;
using namespace std;

int F, S, G, U, D;
int d[1000001];
const int inf = 1e9;

int dp(int pt) {
	int *ret = &d[pt];
	if (*ret != -1) return *ret;
	*ret = inf;
	int prevdownstair = pt - U <= 0 ? inf : dp(pt - U);
	int prevupstair = pt + D > F ? inf : dp(pt + D);
	return *ret = min(min(*ret, prevupstair), prevdownstair)+1;
}

int main(void) {
	cin >> F >> S >> G >> U >> D;
	fill_n(d, F+1, -1);
	d[S] = 0;
	int ans = dp(G);
	if (ans >= inf) {
		cout << "use the stairs";
		return 0;
	}
	cout << ans;
}