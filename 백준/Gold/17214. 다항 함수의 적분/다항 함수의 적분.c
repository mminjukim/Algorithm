#include <stdio.h>
char formula[20];

int getNum(int k) {
	int i = 1, j, n = 0;
	for (j = k; formula[j] >= 48 && formula[j] <= 57 && j >= 0; j--) {
		n += (formula[j] - 48) * i;
		i *= 10;
	}
	return n;
}

int main() {
	scanf("%s", formula); 
	int len = 0, i;
	for (i = 0; formula[i] != 0; i++) len++;
	for (i = 0; formula[i] != 'x'; i++) {
		if (i == 19) break;
	}
	if (i == 19) {
		if (formula[0] == 48)
			printf("W");
		else {
			if (formula[0] == '-') printf("-");
			int num = getNum(len - 1);
			if (num != 1) printf("%d", num);
			printf("x+W");
		}
	}
	else {
		if (formula[0] == '-') printf("-");
		if (formula[i + 1] == '+' || formula[i + 1] == '-') {
			int num1 = getNum(i - 1);
			int num2 = getNum(len - 1);
			if (num1 / 2 != 1) printf("%d", num1 / 2);
			printf("xx%c", formula[i + 1]);
			if (num2 != 1) printf("%d", num2);
			printf("x+W");
		}
		else if (formula[i + 1] == 0) {
			int num = getNum(i - 1);
			if (num / 2 != 1) printf("%d", num / 2);
			printf("xx+W");
		}
	}
	return 0;
}