#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, A, B, ans;
int receive[10];
int repair[10];
int mintime;

typedef struct {
	int come = -1;
	int end = -1;
	int a = -1;
	int b = -1;
	int idx = -1;
}usrtime;

usrtime arrive[1001];

bool cmp(const usrtime& p1, const usrtime& p2) {
	if (p1.come < p2.come) {
		return true;
	}
	else if (p1.come == p2.come) {
		return p1.a < p2.a;
	}
	else {
		return false;
	}
}

void _receive() {
	int time = 0;
	int idx = 1;
	int arr[10] = { 0 };
	int maxend = 0;
	int flag = 0;

	while (1) {
		for (int i = 1; i <= N; i++) {
			if (arr[i] != 0 && arrive[arr[i]].end == time) {
				if (mintime > time) mintime = time;
				arrive[arr[i]].come = time;
				arrive[arr[i]].end = -1;
				arr[i] = 0;
			}
		}
		if (flag == 1 && time > maxend) return;
		for (int i = 1; i <= N && K + 1 > idx; i++) {
			if (arr[i] == 0 && arrive[idx].come <= time) {
				arr[i] = idx;
				arrive[idx].a = i;
				arrive[idx].end = time + receive[i];
				if (arrive[idx].end > maxend) maxend = arrive[idx].end;
				idx++;
				if (idx == K + 1) flag = 1;
			}
		}
		time++;
	}
}
void _repair() {
	int time = mintime;
	int idx = 1;
	int arr[10] = { 0 };

	while (1) {
		for (int i = 1; i <= M; i++) {
			if (arr[i] != 0 && arrive[arr[i]].end == time) {
				arrive[arr[i]].end = -1;
				arr[i] = 0;
			}
		}
		if (idx == K + 1) return;

		for (int i = 1; i <= M && idx < K + 1; i++) {
			if (arr[i] == 0 && arrive[idx].come <= time) {
				arr[i] = idx;
				arrive[idx].b = i;
				arrive[idx].end = time + repair[i];
				idx++;
			}
		}
		time++;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K >> A >> B;
		ans = -1;
		mintime = 987654321;
		for (int i = 1; i <= N; i++)
			cin >> receive[i];
		for (int i = 1; i <= M; i++)
			cin >> repair[i];
		for (int i = 1; i <= K; i++) {
			cin >> arrive[i].come;
			arrive[i].end = -1;
			arrive[i].idx = i;
		}

		_receive();
		sort(arrive + 1, arrive + K + 1, cmp);
		_repair();

 		for (int i = 1; i <= K; i++) {
			if (arrive[i].a == A && arrive[i].b == B) ans += arrive[i].idx;
		}

		if (ans == -1) cout << "#" << tc << " " << ans << '\n';
		else cout << "#" << tc << " " << ans + 1 << '\n';
	}
}