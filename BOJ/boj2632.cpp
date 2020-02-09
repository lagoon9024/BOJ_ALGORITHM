// boj 2632 피자판매
#include <iostream>
#include <vector>
using namespace std;

int buy, a, b, ans;
vector<int> piza;
vector<int> pizb;
int amounta[1000001];
int amountb[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int amount;
	int wpiza = 0, wpizb = 0;
	cin >> buy >> a >> b;
	for (int i = 0; i < a; ++i) {
		cin >> amount;
		piza.push_back(amount);
		wpiza += amount;
	}
	for (int i = 0; i < b; ++i) {
		cin >> amount;
		pizb.push_back(amount);
		wpizb += amount;
	}
	amounta[0] = amountb[0] = 1;
	
	for (int i = 0; i < a; ++i) {
		int tamount = piza[i];
		if (piza[i] <= buy) ++amounta[piza[i]];
		for (int j = 1; j < a; ++j) {
			int idx = i + j;
			if (idx >= a) idx -= a;
			tamount += piza[idx];
			if (tamount > buy) break;
			++amounta[tamount];
		}
	}
	for (int i = 0; i < b; ++i) {
		int tamount = pizb[i];
		if (pizb[i] <= buy) ++amountb[pizb[i]];
		for (int j = 1; j < b; ++j) {
			int idx = i + j;
			if (idx >= b) idx -= b;
			tamount += pizb[idx];
			if (tamount > buy) break;
			++amountb[tamount];
		}
	}
	amounta[wpiza] /= a;
	amountb[wpizb] /= b;
	if (buy > 1000000) buy = 1000000;
	for (int i = 0; i <= buy; ++i) {
		ans += amounta[i] * amountb[buy - i];
	}
	cout << ans;
}
