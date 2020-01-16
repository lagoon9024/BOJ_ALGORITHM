// boj 5214 È¯½Â
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<int> hypertube[1001];
vector<int> station[1000001];
int input;
bool visitpt[100001];
bool visittube[1001];

struct node {
	int tube, dist;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> m;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	int idx = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> input;
			hypertube[idx].push_back(input);
			station[input].push_back(idx);
		}
		++idx;
	}

	queue<node> root;
	for (int i = 0; i < station[1].size(); ++i) {
		root.push({ station[1][i],1 });
	}

	visitpt[1] = true;

	while (!root.empty()) {
		node tmp = root.front();
		root.pop();

		for (int i = 0; i < hypertube[tmp.tube].size(); ++i) {
			int tmppt = hypertube[tmp.tube][i];
			if (tmppt == n) {
				cout << tmp.dist + 1;
				return 0;
			}
			if (visitpt[tmppt]) continue;
			visitpt[tmppt] = true;
			for (int j = 0; j < station[tmppt].size(); ++j) {
				int tmptube = station[tmppt][j];
				if (visittube[tmptube]) continue;
				visittube[tmptube] = true;
				root.push({ station[tmppt][j], tmp.dist + 1 });
			}
		}
	}
	cout << -1;
}