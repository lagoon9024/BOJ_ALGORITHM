// boj 4386 별자리만들기
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n;

struct pos {
	double x, y;
};

struct graph {
	int now, target;
	double dist;
};

struct cmp {
	bool operator()(graph a, graph b){
		return a.dist > b.dist;
		}
};

double distance(pos x, pos y) {
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

int getparent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getparent(set, set[x]);
}

void Union(int set[], int x, int y) {
	x = getparent(set, x);
	y = getparent(set, y);

	if (x < y) set[y] = x;
	else set[x] = y;
}

bool find(int set[], int x, int y) {
	x = getparent(set, x);
	y = getparent(set, y);

	if (x == y) return true;
	return false;
}

int main(void) {
	vector<pos> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		pos tmp;
		cin >> tmp.x >> tmp.y;
		v.push_back(tmp);
	}

	int set[100];
	for (int i = 0; i < v.size(); ++i)
		set[i] = i;

	priority_queue<graph, vector<graph>, cmp> pq;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			pq.push({i,j,distance(v[i],v[j]) });
		}
	}
	double ans = 0;
	while (!pq.empty()) {
		graph tmp = pq.top();
		pq.pop();
		if (!find(set, tmp.now, tmp.target)) {
			ans += tmp.dist;
			Union(set, tmp.now, tmp.target);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
}