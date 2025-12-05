#include <stdio.h>
#include <stdlib.h>

#define INF 1000000001
#define MAX_VERTICES 1000
#define TRUE 1
#define FALSE 0

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int dist[MAX_VERTICES];

void graph_init(GraphType* g, int size) {
	int r, c;
	g->n = size;
	for (r = 0; r < size; r++)
		for (c = 0; c < size; c++)
			g->adj_mat[r][c] = INF;
}

void insert_edge(GraphType* g, int u, int v, int w) {
	if (u >= g->n || v >= g->n)
		return;
	if (g->adj_mat[u][v] < w)
		return;

	g->adj_mat[u][v] = w;
	g->adj_mat[v][u] = w;
}

int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && dist[i] < dist[v])
			v = i;
	return v;
}

int prim(GraphType* g, int s) {
	for (int i = 0; i < g->n; i++)
		dist[i] = INF;
	dist[s] = 0;

	int min_cost = 0;
	for (int i = 0; i < g->n; i++) {
		int u = get_min_vertex(g->n);
		selected[u] = TRUE;
		min_cost += dist[u];
		for (int v = 0; v < g->n; v++)
			if (!selected[v] && g->adj_mat[u][v] < dist[v])
				dist[v] = g->adj_mat[u][v];
	}
	return min_cost;
}

int main(void) {
	int V, E;
	scanf("%d\n%d", &V, &E);

	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g, V);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		insert_edge(g, u - 1, v - 1, w);
	}

	printf("%d\n", prim(g, 0));
}