#include <stdio.h>

int map[20][20];
int diceNum[6];
int diceSide[6] = { 0,1,2,3,4,5 };
int H, Y;

int main() {
	int h, y, order, i, j;
	scanf("%d %d %d %d %d", &H, &Y, &h, &y, &order);
	for (i = 0; i < H; i++) {
		for (j = 0; j < Y; j++)
			scanf("%d", &map[i][j]);
	}
	
	for (i = 0; i < order; i++) {
		int way;
		scanf("%d", &way);

		int saveDiceSide[6] = { 0 };
		for (j = 0; j < 6; j++)
			saveDiceSide[j] = diceSide[j];

		if (way == 1) {
			if (y + 1 >= Y)
				continue;
			else
				y += 1;

			diceSide[0] = saveDiceSide[3];
			diceSide[2] = saveDiceSide[0];
			diceSide[3] = saveDiceSide[5];
			diceSide[5] = saveDiceSide[2];
		}

		else if (way == 2) {
			if (y - 1 < 0)
				continue;
			else
				y -= 1;

			diceSide[0] = saveDiceSide[2];
			diceSide[3] = saveDiceSide[0];
			diceSide[2] = saveDiceSide[5];
			diceSide[5] = saveDiceSide[3];
		}

		else if (way == 3) {
			if (h - 1 < 0)
				continue;
			else
				h -= 1;

			diceSide[0] = saveDiceSide[4];
			diceSide[5] = saveDiceSide[1];
			diceSide[1] = saveDiceSide[0];
			diceSide[4] = saveDiceSide[5];
		}

		else if (way == 4) {
			if (h + 1 >= H)
				continue;
			else
				h += 1;

			diceSide[0] = saveDiceSide[1];
			diceSide[4] = saveDiceSide[0];
			diceSide[1] = saveDiceSide[5];
			diceSide[5] = saveDiceSide[4];
		}

		if (map[h][y] > 0) {
			diceNum[diceSide[5]] = map[h][y];
			map[h][y] = 0;
		}

		else {
			map[h][y] = diceNum[diceSide[5]];
		}

		printf("%d\n", diceNum[diceSide[0]]);
	}
}