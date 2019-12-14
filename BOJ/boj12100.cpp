//boj 12100
#include <iostream>

using namespace std;

int N;
int map[20][20];
int _max = 0;

//dir  0 left 1 right 2 up 3 down

void _2048(int tmpmap[20][20], int dir, int depth){
	if (depth > 5) return;
	int board[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = tmpmap[i][j];
		}
	}
	switch (dir) {
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					int tmpj = j;
					while (board[i][tmpj] == 0 && tmpj < N - 1) tmpj++;
					if (board[i][tmpj] != 0) {
						board[i][j] = board[i][tmpj];
						board[i][tmpj] = 0;
					}
				}
			}
			for (int j = 0; j < N-1; j++) {
				if (board[i][j] != 0 && board[i][j + 1] == board[i][j]) {
					board[i][j] *= 2;
					board[i][j + 1] = 0;
				}
			}
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					int tmpj = j;
					while (board[i][tmpj] == 0 && tmpj < N - 1) tmpj++;
					if (board[i][tmpj] != 0) {
						board[i][j] = board[i][tmpj];
						board[i][tmpj] = 0;
					}
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j >=0; j--) {
				if (board[i][j] == 0) {
					int tmpj = j;
					while (board[i][tmpj] == 0 && tmpj > 0) tmpj--;
					if (board[i][tmpj] != 0) {
						board[i][j] = board[i][tmpj];
						board[i][tmpj] = 0;
					}
				}
			}
			for (int j = N - 1; j > 0; j--) {
				if (board[i][j] != 0 && board[i][j-1]==board[i][j]) {
					board[i][j] *= 2;
					board[i][j - 1] = 0;
				}
			}
			for (int j = N-1; j >=0; j--) {
				if (board[i][j] == 0) {
					int tmpj = j;
					while (board[i][tmpj] == 0 && tmpj > 0) tmpj--;
					if (board[i][tmpj] != 0) {
						board[i][j] = board[i][tmpj];
						board[i][tmpj] = 0;
					}
				}
			}
		}
		break;
	case 2:
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (board[i][j] == 0) {
					int tmpi = i;
					while (board[tmpi][j] == 0&& tmpi<N-1) tmpi++;
					if (board[tmpi][j] != 0) {
						board[i][j] = board[tmpi][j];
						board[tmpi][j] = 0;
					}
				}
			}
			for (int i = 0; i < N-1; i++) {
				if (board[i][j] != 0 && board[i + 1][j] == board[i][j]) {
					board[i][j] *= 2;
					board[i + 1][j] = 0;
				}
			}
			for (int i = 0; i < N; i++) {
				if (board[i][j] == 0) {
					int tmpi = i;
					while (board[tmpi][j] == 0 && tmpi < N - 1) tmpi++;
					if (board[tmpi][j] != 0) {
						board[i][j] = board[tmpi][j];
						board[tmpi][j] = 0;
					}
				}
			}
		}
		break;
	case 3:
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] == 0) {
					int tmpi = i;
					while (board[tmpi][j] == 0 && tmpi >0) tmpi--;
					if (board[tmpi][j] != 0) {
						board[i][j] = board[tmpi][j];
						board[tmpi][j] = 0;
					}
				}
			}
			for (int i = N - 1; i >0; i--) {
				if (board[i][j] != 0 && board[i - 1][j] == board[i][j]) {
					board[i][j] *= 2;
					board[i - 1][j] = 0;
				}
			}
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] == 0) {
					int tmpi = i;
					while (board[tmpi][j] == 0 && tmpi > 0) tmpi--;
					if (board[tmpi][j] != 0) {
						board[i][j] = board[tmpi][j];
						board[tmpi][j] = 0;
					}
				}
			}
		}
		break;
	}
	// cout << "DIR : " << dir << " DEPTH : " << depth << '\n';
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > _max) _max = board[i][j];
			if (board[i][j] != tmpmap[i][j]) flag = 1;
	//		cout << board[i][j] << " ";
		}
	//	cout << '\n';
	}
	if (flag == 0) return;

	for (int i = 0; i < 4; i++)
		_2048(board, i, depth + 1);
}

void sol() {
	for (int k = 0; k < 4; k++) {
		_2048(map, k, 1);
	}

	cout << _max;
}

int main(void) {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	sol();

}