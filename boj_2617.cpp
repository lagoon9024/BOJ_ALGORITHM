#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int res = 0;
int flag = 0;
int N, cnt;
int arr1[100] = { 0 };
int arr2[100] = { 0 };
vector<int> v1[100];
vector<int> v2[100];

void updfs(int idx) {
	for (int i = 0; i < v1[idx].size(); i++) {
		if (arr1[v1[idx][i]] == 0)
		{
			arr1[v1[idx][i]] = 1;
			cnt++;
			updfs(v1[idx][i]);
		}
	}
}

void downdfs(int idx) {
	for (int i = 0; i < v2[idx].size(); i++) {
	if (arr2[v2[idx][i]] == 0)
	{
		arr2[v2[idx][i]] = 1;
		cnt++;
		downdfs(v2[idx][i]);
		}
	}
}

int main(void) {
	int M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p, q;
		cin >> p >> q;
		v1[p].push_back(q);
		v2[q].push_back(p);
	}

	for (int i = 1; i <= N; i++) {
		if (v1[i].empty() && v2[i].empty()) continue;

		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		cnt = 0;
		flag = 0;
		updfs(i);
		if (cnt >= (N + 1) / 2) {
			res++;
		}
		//cout << "up" << i << " " << cnt << '\n';

		cnt = 0;
		flag = 0;
		downdfs(i);
		if (cnt >= (N + 1) / 2) {
			res++;
		}
		//cout << "down" << i << " " << cnt << '\n';
	}
	cout << res;
}