#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[12];
int sorted[12][2];
int card[12];
int N;
typedef struct {
	int arr[12];
	int cnt;
}CARD;


void issorted() {
	for (int i = 0; i < N; i++) {
		sorted[i][0] = i + 1;
		sorted[i][1] = N - i;
	}
	return;
}

int sortchk(CARD tmpcard) {
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (sorted[i][0] != tmpcard.arr[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			if (sorted[i][1] != tmpcard.arr[i]) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0) return 0;
	else return -1;
}

int bfs() {
	queue<CARD> q;
	CARD tcard;
	for (int i = 0; i < N; i++) {
		tcard.arr[i] = card[i];
	}
	tcard.cnt = 0;
	q.push(tcard);

	while (!q.empty()) {
		CARD tmpcard = q.front();
		q.pop();

		//cout << "Depth : " << tmpcard.cnt << '\n';
		//for (int i = 0; i < N; i++)
		//	cout << tmpcard.arr[i] << " ";
		//cout << '\n';

		if (tmpcard.cnt > 5) {
			return -1;
		}

		if (sortchk(tmpcard) == 0) return tmpcard.cnt;
		
		for (int i = 0; i < N / 2; i++) {
				arr[i] = 0;
			}
		for (int i = N / 2; i < N; i++) {
				arr[i] = 1;
		}
		CARD ttmpcard;
			for (int i = 0; i < N; i++)
				ttmpcard.arr[i] = tmpcard.arr[i];
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N-1; j++) {
				if (arr[j] == 0 && arr[j + 1] == 1) {
					swap(ttmpcard.arr[j], ttmpcard.arr[j + 1]);
					swap(arr[j], arr[j + 1]);
					j++;
				}
			}
			
			//cout << tmpcard.cnt << '\n';
			//for (int j = 0; j < N; j++)
			//	cout << ttmpcard.arr[j] << " ";
			//cout << '\n';
		
			ttmpcard.cnt = tmpcard.cnt + 1;

			if (sortchk(ttmpcard) == 0) return ttmpcard.cnt;
			q.push(ttmpcard);

		}
	}

}


int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		fill_n(arr, 12, -1);
		for (int i = 0; i < N / 2; i++) {
			cin >> card[i];
		}
		for (int i = N / 2; i < N; i++) {
			cin >> card[i];
		}
		issorted();
		
		cout << "#"<<tc<< " "<< bfs() <<'\n';

	}
}

//
//5
//4
//1 2 3 4
//4
//4 2 3 1
//6
//6 5 4 2 3 1
//8
//6 1 4 7 2 5 8 3
//12
//2 7 4 1 3 5 8 10 12 9 6 11

//#1 0
//#2 1
//#3 - 1
//#4 3
//#5 5