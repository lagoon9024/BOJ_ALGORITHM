// boj 1202 º¸¼® µµµÏ
#include <iostream>
#include <algorithm>

using namespace std;

class jewel {
public:
	int mass, val;
	jewel() {
		mass = 0;
		val =0;
	}
	jewel(int m, int v) {
		this->mass = m;
		this->val = v;
	}
};
jewel jewels[300000];
jewel heap[300001];
int bags[300000];
int idx;

bool compare(jewel c, jewel p) {
	if (c.val > p.val) return true;
	else if (c.val == p.val) {
		if (c.mass <= p.mass) return true;
	}
	else return false;
}
bool compare2(jewel j1, jewel j2) {
	if (j1.mass < j2.mass) return true;
	else return false;
}

void push(jewel jew) {
	heap[++idx] = jew;

	int child = idx;
	int parent = idx / 2;
	while (child > 1 && compare(heap[child], heap[parent])) {
		jewel tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;
		child = parent;
		parent = child / 2;
	}
}

jewel pop() {
	jewel ret = heap[1];
	heap[1] = heap[idx];
	--idx;
	int parent = 1;
	int child = parent << 1;
	if (child + 1 <= idx && compare(heap[child+1], heap[child])) child = child + 1;

	while (child <= idx && compare(heap[child], heap[parent])) {
		jewel tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;
		parent = child;
		child <<= 1;
		if (child + 1 <= idx && compare(heap[child + 1], heap[child])) child = child + 1;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> jewels[i].mass >> jewels[i].val;
	}
	for (int i = 0; i < k; ++i) {
		cin >> bags[i];
	}
	sort(bags, bags + k);
	sort(jewels, jewels + n, compare2);
	long long ans = 0;
	int nidx = 0;
	for (int i = 0; i < k; ++i) {
		while (nidx < n && jewels[nidx].mass <= bags[i])
			push(jewels[nidx++]);
		if (idx > 0) {
			ans += pop().val;
		}
	}
	cout << ans;
}