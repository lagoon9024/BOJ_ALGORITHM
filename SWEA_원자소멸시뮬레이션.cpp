#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

typedef struct atom {
	int r;
	int c;
	int dir; // 0 up 1 down 2 left 3 right
	int E;
	int idx;
}atom;

int MAP[4001][4001][2];
int sum, N;
int atomcnt;
int movecnt;

atom move(atom uzu) {
	switch (uzu.dir) {
	case(0):
		uzu.r++;
		if (uzu.r > 2000) uzu.E = -1;
		break;
	case(1):
		uzu.r--;
		if (uzu.r < -2000) uzu.E = -1;
		break;
	case(2):
		uzu.c--;
		if (uzu.c < -2000) uzu.E = -1;
		break;
	case(3):
		uzu.c++;
		if (uzu.c > 2000) uzu.E = -1;
		break;
	}
	return uzu;
}

void mapping(atom* uzu) {
	//

	for (int i = 1; i <= N; i++) {
		if (uzu[i].E == -1) continue;
		if (MAP[uzu[i].r + 2000][uzu[i].c + 2000][1] != movecnt) {
			MAP[uzu[i].r + 2000][uzu[i].c + 2000][0] = uzu[i].idx;
			MAP[uzu[i].r + 2000][uzu[i].c + 2000][1] = movecnt;
		}
		else if (MAP[uzu[i].r + 2000][uzu[i].c + 2000][0] == -1 && MAP[uzu[i].r + 2000][uzu[i].c + 2000][1] == movecnt)
		{
			//printf("before sum %d\n", sum);
			//printf("val : %d\n", uzu[i].E);
			sum += uzu[i].E;
			uzu[i].E = -1;
			atomcnt--;
			//printf("after sum %d\n", sum);

		}
		else if (MAP[uzu[i].r + 2000][uzu[i].c + 2000][1]==movecnt) {
			sum += uzu[MAP[uzu[i].r + 2000][uzu[i].c + 2000][0]].E + uzu[i].E;
			uzu[MAP[uzu[i].r + 2000][uzu[i].c + 2000][0]].E = uzu[i].E = -1;
			MAP[uzu[i].r + 2000][uzu[i].c + 2000][0] = -1;
			atomcnt -= 2;
		}		
	}
}


int main(void) {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		sum = 0;
		movecnt = 0;
		memset(MAP, 0, sizeof(MAP));
		scanf("%d", &N);
		atom* atoms;
		atoms = (atom*)malloc(sizeof(atom) * (N + 1));
		atomcnt = N;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d %d", &atoms[i].c, &atoms[i].r, &atoms[i].dir, &atoms[i].E);
			atoms[i].idx = i;
			atoms[i].c *= 2;
			atoms[i].r *= 2;
			/*scanf("%d", &atoms[i].c);
			scanf("%d", &atoms[i].r);
			scanf("%d", &atoms[i].dir);
			scanf("%d", &atoms[i].E);*/
		}

		/*	for (int i = 0; i < N; i++) {
				printf("%d %d %d %d %d\n", atoms[i].c, atoms[i].r, atoms[i].dir, atoms[i].E, atoms[i].idx);
			}*/

		for (int i = 0; i < 4000; i++) {
			if (atomcnt == 0) break;
			movecnt++;
			for (int j = 1; j <= N; j++) {
				if (atoms[j].E == -1)continue;
				atoms[j] = move(atoms[j]);
			}
			mapping(atoms);
			
			//		printf("#mapval%d %d\n", i, sum);
			//		printf("%d\n", sum);
		}

		//for (int i = 0; i < N; i++) {
		//	printf("%d %d %d %d\n", atoms[i].c, atoms[i].r, atoms[i].dir, atoms[i].E);
		//}
		printf("#%d %d\n", tc, sum);
		//printf("%d\n", sum);
		free(atoms);
	}
}