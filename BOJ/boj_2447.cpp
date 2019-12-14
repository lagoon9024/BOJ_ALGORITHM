//boj 2447
#include <iostream>

using namespace std;

char map[2200][2200];

void stars(int y, int x, int num)
{
	if (num == 1)
	{
		map[y][x] = '*';
		return;
	}

	int div = num / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i!=1 || j!=1)
				stars(y + (i * div), x + (j * div), div);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		fill_n(map[i], n, ' ');
	stars(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}