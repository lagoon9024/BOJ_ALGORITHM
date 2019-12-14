//boj 17471
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
int region[11] = { 0 };
int map[11][11] = { 0 };
bool check[11];
vector<int> v1;
vector<int> v2;
int ans = -1;

void makev2(int pt);

void makev1(int pt, int depth) {
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			makev2(i);
			break;
		}
	}
	
	if (depth == N-1) return;

	for (int i = 1; i <= N; i++) {
		if (check[i] == false && map[pt][i] == 1) {
			check[i] = true;
			v1.push_back(i);
			makev1(i, depth + 1);
			check[i] = false;
			v1.pop_back();
		}
	}
}

void makev2(int pt) {
	queue<int> q;
	q.push(pt);
	v2.push_back(pt);
	check[pt] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[tmp][i] == 1 && check[i] == false) {
				check[i] = true;
				v2.push_back(i);
				q.push(tmp);
			}
		}
	}

	if (v1.size() + v2.size() == N) {
		cout << "\n V1: ";
		for (unsigned int i = 0; i < v1.size(); i++) {
			cout <<  v1[i]<<" ";
		}
		cout << "\n V2: ";
		for (unsigned int i = 0; i < v2.size(); i++) {
			cout << v2[i]<< " ";
		}

		int sum1, sum2;
		sum1 = sum2 = 0;
		for (unsigned int i = 0; i < v1.size(); i++) {
			sum1 = sum1 + region[v1[i]];
		}
		for (unsigned int i = 0; i < v2.size(); i++) {
			sum2 = sum2 + region[v2[i]];
		}

		if (sum1 - sum2 < 0) {
			if (ans == -1)
				ans = sum2 - sum1;
			else {
				if (sum2 - sum1 < ans)
					ans = sum2 - sum1;
			}
		}
		else {
			if (ans == -1)
				ans = sum1 - sum2;
			else {
				if (sum1 - sum2 < ans)
					ans = sum1 - sum2;
			}
		}
	}

	while (!v2.empty()) {
		int i = v2[v2.size()-1];
		check[i] = false;
		v2.pop_back();
	}
}


int main(void){
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> region[i];

	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int l;
			cin >> l;
			map[i][l] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
			check[i] = true;
			v1.push_back(i);
			makev1(i, 1);
			check[i] = false;
			v1.pop_back();
		}

	cout << ans;
}