#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 1001
#define INF LONG_MAX / 2

typedef struct GraphType {
	int n;
	long weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

long long distance[MAX_VERTICES];
int found[MAX_VERTICES];

void graph_init(GraphType* g, int n) {
	g->n = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			g->weight[i][j] = INF;
			g->weight[j][i] = INF;
		}
}

void insert_edge(GraphType* g, int u, int v, int weight) {
	if (weight < g->weight[u][v]) {
		g->weight[u][v] = weight;
	}
}

int choose(long long distance[], int n, int found[]) {
	int i, minpos;
	long long min = LONG_MAX;
	minpos = 0;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

long long shortest_path(GraphType* g, int start, int end) {
	int i, u, w;

	// 초기화
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}

	// 시작 정점 설정
	found[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < g->n; i++) {
		// 현재 최소 거리 u 선택
		u = choose(distance, g->n, found);
		found[u] = TRUE;

		// 선택된 점이 도착점이라면 종료 및 반환
		if (u == end) {
			return distance[u];
		}

		// 새로 선택된 u 기준 업데이트
		for (w = 0; w < g->n; w++)
			if (!found[w] && distance[u] + g->weight[u][w] < distance[w]) {
				distance[w] = distance[u] + g->weight[u][w];
			}
	}

	return 0;
}

int main(void) {
	int N, M, u, v, w;
	int start, end;

	GraphType* g = (GraphType*)malloc(sizeof(GraphType));

	scanf("%d\n%d", &N, &M);
	graph_init(g, N);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insert_edge(g, u - 1, v - 1, w);
	}

	scanf("%d %d", &start, &end);
	printf("%lld\n", shortest_path(g, start - 1, end - 1));
}