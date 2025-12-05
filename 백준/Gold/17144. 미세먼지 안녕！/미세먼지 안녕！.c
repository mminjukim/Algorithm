#include <stdio.h>

int room[55][55];
int newroom[55][55];
int dust[55][55];
int windWay[55][55];
int ch[4] = { -1,0,1,0 };
int cy[4] = { 0,1,0,-1 };

int main() {
	int H, Y, T, i, j, k;
	for (i = 0; i < 52; i++) {
		for (j = 0; j < 52; j++)
			room[i][j] = -2; 
	}
	scanf("%d %d %d", &H, &Y, &T); 
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= Y; j++)
			scanf("%d", &room[i][j]); 
	}

	int c1h, c2h;
	for (i = 1; i <= H; i++) {
		if (room[i][1] == -1) {
			c1h = i;
			break;
		}
	}
	for (i = H; i >= 1; i--) {
		if (room[i][1] == -1) {
			c2h = i;
			break;
		}
	}

	for (i = 2; i < Y; i++) {
		windWay[c1h][i] = 2;
		windWay[c2h][i] = 2;
	}
	for (i = c1h; i > 1; i--) windWay[i][Y] = 1;
	for (i = c2h; i < H; i++) windWay[i][Y] = 3;
	for (i = Y; i > 1; i--) {
		windWay[1][i] = 4;
		windWay[H][i] = 4;
	}
	for (i = 1; i < c1h; i++) windWay[i][1] = 3;
	for (i = H; i > c2h; i--) windWay[i][1] = 1;

	for (int time = 0; time < T; time++) {
		for (i = 1; i <= H; i++) {
			for (j = 1; j <= Y; j++) {
				int wCnt = 0;
				for (k = 0; k < 4; k++) {
					if (room[i + ch[k]][j + cy[k]] >= 0) {
						dust[i + ch[k]][j + cy[k]] += room[i][j] / 5;
						wCnt++;
					}
				}
				room[i][j] -= (room[i][j] / 5) * wCnt;
			}
		}
		for (i = 1; i <= H; i++) {
			for (j = 0; j <= Y; j++)
				room[i][j] += dust[i][j];
		}
		for (i = 1; i <= H; i++) {
			for (j = 0; j <= Y; j++)
				dust[i][j] = 0;
		}

		for (i = 1; i <= H; i++) {
			for (j = 1; j <= Y; j++) {
				switch (windWay[i][j]) {
				case 1:
					newroom[i - 1][j] = room[i][j];
					if (room[i - 1][j] == -1)
						newroom[i - 1][j] = -1;
					break;
				case 2:
					newroom[i][j + 1] = room[i][j];
					break;
				case 3:
					newroom[i + 1][j] = room[i][j];
					if (room[i + 1][j] == -1)
						newroom[i + 1][j] = -1;
					break;
				case 4:
					newroom[i][j - 1] = room[i][j];
					break;
				default:
					newroom[i][j] = room[i][j];
				}
			}
		}
		for (i = 1; i <= H; i++) {
			for (j = 1; j <= Y; j++) {
				room[i][j] = newroom[i][j];
				newroom[i][j] = 0;
			}
		}
	}

	int dustSum = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= Y; j++)
			if (room[i][j] > 0)
				dustSum += room[i][j];
	}
	printf("%d", dustSum);

	return 0;
}