#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001

int parent[MAX_VERTICES];
int num[MAX_VERTICES];

void set_init(int n) {
	int i;
	for (i = 1; i <= n; i++) {
		parent[i] = -1;
		num[i] = 1;
	}
}

int set_find(int vertex) {
	int p, s, i = -1;
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		;
	s = i;
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		parent[i] = s;
	return s;
}

void set_union(int s1, int s2) {
	if (num[s1] < num[s2]) {
		parent[s1] = s2;
		num[s2] += num[s1];
		num[s1] = 0;
	} else {
		parent[s2] = s1;
		num[s1] += num[s2];
		num[s2] = 0;
	}
}

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct {
	GraphNode* adj_list[MAX_VERTICES];
	int n;
} GraphType;

void init(GraphType* g, int n) {
	g->n = n;
	for (int i = 1; i <= n; i++)
		g->adj_list[i] = NULL;
}

void insert_edge(GraphType* g, int u, int v) {
	if (u > g->n || v > g->n) {
		return;
	}

	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

int main(void) {
	int N, M;
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));

	scanf("%d %d", &N, &M);
	init(g, N);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		insert_edge(g, u, v);
	}

	set_init(g->n);

	for (int i = 1; i <= N; i++) {
		for (GraphNode* j = g->adj_list[i]; j != NULL; j = j->link) {
			int uset = set_find(i);
			int vset = set_find(j->vertex);
			if (uset != vset) {
				set_union(uset, vset);
			}
		}
	}

	int component_cnt = 0;
	for (int i = 1; i <= N; i++)
		if (num[i] > 0)
			component_cnt++;

	printf("%d\n", component_cnt);

	return 0;
}