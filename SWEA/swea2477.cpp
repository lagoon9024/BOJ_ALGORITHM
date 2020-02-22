// swea 2477 차량정비소
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, a, b;
int receive[9], repair[9], arrival[1000], cusr[1000], cusrep[1000], whoina[9], aend[9], bend[9];

class waiting {
public:
	int time, idx, cust;
	waiting(int t, int i, int c) {
		this->time = t;
		this->idx = i;
		this->cust = c;
	}
};

bool comp(waiting a, waiting b) {
	if (a.time == b.time) {
		return a.idx > b.idx;
	}
	return a.time > b.time;
}

vector<waiting> Bwaiting;

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int ans = 0;
		cin >> n >> m >> k >> a >> b;
		fill_n(whoina, n, -1);
		fill_n(aend, n, 0);
		fill_n(bend, m, 0);
		Bwaiting.clear();
		for (int i = 0; i < n; ++i)
			cin >> receive[i];
		for (int i = 0; i < m; ++i)
			cin >> repair[i];

		for (int i = 0; i < k; ++i) {
			cin >> arrival[i];
			int minend = 1e9, index = 0, flag = 0;
			for (int idx = 0; idx < n; ++idx) {
				if (aend[idx] <= arrival[i]) {
					if (whoina[idx] == -1) whoina[idx] = i;
					else {
						Bwaiting.push_back(waiting(aend[idx], idx, whoina[idx]));
						whoina[idx] = i;
					}
					aend[idx] = arrival[i] + receive[idx];
					cusr[i] = idx;
					flag = 1;
					break;
				}
				if (aend[idx] < minend) { minend = aend[idx]; index = idx; }
			}
			if (!flag) {
				Bwaiting.push_back(waiting(aend[index], index, whoina[index]));
				whoina[index] = i;
				aend[index] = aend[index] + receive[index];
				cusr[i] = index;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (whoina[i] > 0) {
				Bwaiting.push_back(waiting(aend[i], i, whoina[i]));
				whoina[i] = -1;
			}
		}
		sort(Bwaiting.begin(), Bwaiting.end(), comp);

		for (int i = 0; i < k; ++i) {
			waiting tmp = Bwaiting.back();
			Bwaiting.pop_back();
			int minend = 1e9, index = 0, flag = 0;
			for (int idx = 0; idx < m; ++idx) {
				if (bend[idx] <= tmp.time) {
					bend[idx] = tmp.time + repair[idx];
					cusrep[tmp.cust] = idx;
					flag = 1;
					break;
				}
				if (bend[idx] < minend) { minend = bend[idx]; index = idx; }
			}
			if (!flag) {
				bend[index] = bend[index] + repair[index];
				cusrep[tmp.cust] = index;
			}
		}

		for (int i = 0; i < k; ++i) {
			if (cusr[i] + 1 == a && cusrep[i] + 1 == b) ans += (i + 1);
		}
		if (!ans) ans = -1;

		cout << '#' << tc << " " << ans << '\n';
	}
}