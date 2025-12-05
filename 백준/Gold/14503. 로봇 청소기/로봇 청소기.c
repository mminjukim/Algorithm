#include <stdio.h>

int main(void) {
	int room[51][51] = { 0 };
	int N, M, r, c, d;
	int i, j;
	int cleanCnt = 0;
	int uncleaned = 0;
	int near[8] = { -1, 0, 0, 1, 1, 0, 0, -1 };

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++)
			scanf("%d", &room[i][j]);
	
	while (1) {
		if (room[r][c] == 0) {
			room[r][c] = 2;
			cleanCnt++;
		}

		uncleaned = 0;
		for (i = 0; i < 7; i += 2)
			if (room[r + near[i]][c + near[i + 1]] == 0)
				uncleaned++;

		if (uncleaned > 0)
			while (1) {
				d--;
				if (d < 0) d = 3;
				if (d == 0 && room[r - 1][c] == 0) {
					r--;
					break;
				}
				else if (d == 1 && room[r][c + 1] == 0) {
					c++;
					break;
				}
				else if (d == 2 && room[r + 1][c] == 0) {
					r++;
					break;
				}
				else if (d == 3 && room[r][c - 1] == 0) {
					c--;
					break;
				}
				else
					continue;
			}
		else 
			if (d == 0) {
				if (room[r + 1][c] != 1)
					r++;
				else
					break;
			}
			else if (d == 1) {
				if (room[r][c - 1] != 1)
					c--;
				else
					break;
			}
			else if (d == 2) {
				if (room[r - 1][c] != 1)
					r--;
				else
					break;
			}
			else {
				if (room[r][c + 1] != 1)
					c++;
				else
					break;
			}
	}

	printf("%d\n", cleanCnt);
	return 0;
}