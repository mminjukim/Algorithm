#include <stdio.h>

int growth[1400];

int main() {
	int i, j, k, l, M, N;
	scanf("%d %d", &M, &N);

	for (i = 0; i < N; i++) {
		k = 0;
		for (l = 0; l < 3; l++) {
			int tmp;
			scanf("%d", &tmp);
			for (j = 0; j < tmp; j++) {
				growth[k] += l;
				k++;
			}
		}
	}

	for (j = M - 1; j >= 0; j--) {
		printf("%d ", growth[j] + 1);
		for (i = M; i < 2 * M - 1; i++) {
			printf("%d ", growth[i] + 1);
		}
		printf("\n");
	}

	return 0;
}