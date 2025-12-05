#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100001

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int size;
} HeapType;

void heap_init(HeapType* h) {
	h->size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i = ++h->size;
	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	if (h->size == 0) {
		element e = {0};
		return e;
	}
	element item = h->heap[1];
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;
	while (child <= h->size) {
		if (child < h->size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	int N, i, x;
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x) {
			element e = {x};
			insert_max_heap(h, e);
		} else {
			printf("%d\n", delete_max_heap(h).key);
		}
	}

	free(h);
	return 0;
}