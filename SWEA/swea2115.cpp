// swea 2115 ¹ú²ÜÃ¤Ãë
#include <iostream>
#include <vector>

using namespace std;

int n, m, c;
int honey[10][10];
bool visit[10][10];
int val;

bool desc(int a, int b) {
	return a > b;
}

void permute(vector<int> v, int idx, int sval, int amount, int depth) {
	if (amount > c) return;
	if (depth == m) return;
	if (sval > val) val = sval;
	for (int i = idx + 1; i < v.size(); ++i)
		permute(v, i, sval + (v[i]*v[i]), amount + v[i], depth + 1);
}

vector<int> got;

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int ans = 0;
		cin >> n >> m >> c;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> honey[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - m + 1; ++j) {
				int amount = 0;
				int mainval = 0;
				val = 0;
				for (int k = 0; k < m; ++k) {
					visit[i][j + k] = true;
					got.push_back(honey[i][j + k]);
					amount += honey[i][j + k];
				}

				if (amount > c) {
					sort(got.begin(), got.end(), desc);
					for (int l = 0; l < got.size(); ++l) {
						for (int k = l; k < got.size(); ++k) {
							permute(got, k, got[k] * got[k], got[k], 0);
						}
					}
				}
				else {
					for (int k = 0; k < got.size(); ++k) {
						val += got[k] * got[k];
					}
				}
				got.clear();

				mainval = val;
				// subtask
				int subval = 0;

				for (int p = 0; p < n; ++p) {
					for (int q = 0; q < n - m + 1; ++q) {
						bool flag = false;
						for (int r = 0; r < m; ++r) {
							if (visit[p][q + r]) {
								flag = true;
								break;
							}
						}
						if (flag) continue;
						amount = 0;
						for (int r = 0; r < m; ++r) {
							got.push_back(honey[p][q + r]);
							amount += honey[p][q + r];
						}
						val = 0;
						if (amount > c) {
							for (int k = 0; k < got.size(); ++k) {
								permute(got, k, got[k]*got[k], got[k], 0);
							}
						}
						else {
							for (int k = 0; k < got.size(); ++k) {
								val += got[k] * got[k];
							}
						}
						if (val > subval) subval = val;
						got.clear();
					}
				}
				if (mainval + subval > ans) ans = mainval + subval;
				for (int k = 0; k < m; ++k) {
					visit[i][j + k] = false;
				}
			}
		}
		cout << '#' << tc << " " << ans << '\n';
	}
}