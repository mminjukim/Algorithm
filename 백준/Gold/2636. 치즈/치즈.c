#include <stdio.h>

int p[102][102];
int pSave[102][102];
int visit[102][102];
int ch[4] = { -1,1,0,0 };
int cy[4] = { 0,0,-1,1 };
int H, Y;

void Border(int h, int y) {
	if (h == 0 || y == 0 || h > H || y > Y) return;
	if (visit[h][y] > 0) return;

	visit[h][y] = 1;
	if (p[h][y] == 0) {
		for (int i = 0; i < 4; i++)
			Border(h + ch[i], y + cy[i]);
	}
	else {
		p[h][y] = 2;
		return;
	}
}

int main() {
	int t = 0, i, j;
	scanf("%d %d", &H, &Y);

	for (i = 1; i <= H; i++) {
		for (j = 1; j <= Y; j++)
			scanf("%d", &p[i][j]); 
	}

	for (int k = 0; ; k++) {
		for (i = 0; i < 102; i++) {
			for (j = 0; j < 102; j++)
				visit[i][j] = 0;
		}

		for (i = 0; i < 102; i++) {
			for (j = 0; j < 102; j++)
				pSave[i][j] = p[i][j];
		}

		Border(1, 1);
        
		for (i = 1; i <= H; i++) {
			for (j = 1; j <= Y; j++) {
				if (p[i][j] == 2) 
                    p[i][j] = 0;
			}
		}

		t++;
		int chzCnt = 0;
		for (i = 1; i <= H; i++) {
			for (j = 1; j <= Y; j++) {
				if (p[i][j] > 0) 
                    chzCnt++;
			}
		}
		if (chzCnt == 0) break;
	}

	int hourBeforeCnt = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= Y; j++) {
			if (pSave[i][j] > 0) 
                hourBeforeCnt++;
		}
	}

	printf("%d\n%d", t, hourBeforeCnt);
	return 0;
}