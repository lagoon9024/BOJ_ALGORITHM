// boj 6603 lotto
#include <iostream>
#include <vector>

using namespace std;
int arr[13];
vector<int> v;

void makelotto(int start, int k, int depth) {
	if (depth == 5) {
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = start+1; i < k; ++i) {
		v.push_back(arr[i]);
		makelotto(i, k, depth+1);
		v.pop_back();
	}
}

int main(void) {
	int k = -1;
	
	while (1) {
		cin >> k;
		if (k == 0) return 0;

		for (int i = 0; i < k; ++i)
			cin >> arr[i];
		
		for (int i = 0; i < k - 5; ++i) {
			v.push_back(arr[i]);
			makelotto(i, k, 0);
			v.pop_back();
		}

		cout << '\n';
	}
}