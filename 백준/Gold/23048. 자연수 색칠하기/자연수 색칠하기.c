#include <stdio.h>
int nArr[500002];
int visit[500002];
int N;

void colorN(int n, int colorNumber) {  
    for (int i = 1; n * i <= N; i++) {
        nArr[n * i] = colorNumber;
        visit[n * i] = 1;
    }
    return;
}

int main() {
    int K = 1;
    nArr[1] = 1;
    scanf("%d", &N);
    if (N == 1) {
        printf("1\n1");
        return 0;
    }
    
    K = 2;
    for (int i = 2; i <= N; i++) {
        if (visit[i] == 0) {
            colorN(i, K);
            K++;
        }
    }
    printf("%d\n", K - 1);
    for (int i = 1; i <= N; i++) {
        printf("%d ", nArr[i]);
    }
    return 0;
}