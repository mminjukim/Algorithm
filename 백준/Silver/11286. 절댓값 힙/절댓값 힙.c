#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100001

typedef struct {
	int key;
	int original;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int size;
} HeapType;

void heap_init(HeapType* h) {
	h->size = 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i = ++h->size;
	while (i != 1 && (item.key < h->heap[i / 2].key ||
					  (item.key == h->heap[i / 2].key &&
					   item.original < h->heap[i / 2].original))) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	if (h->size == 0) {
		element e = {0, 0};
		return e;
	}
	element item = h->heap[1];
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;
	while (child <= h->size) {
		if (child < h->size &&
			(h->heap[child].key > h->heap[child + 1].key ||
			 (h->heap[child].key == h->heap[child + 1].key &&
			  h->heap[child].original > h->heap[child + 1].original)))
			child++;
		if (temp.key < h->heap[child].key ||
			(temp.key == h->heap[child].key &&
			 temp.original < h->heap[child].original))
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	int N, x;
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	heap_init(h);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", delete_min_heap(h).original);
		} else {
			int key = (x > 0) ? x : -x;
			element e = {key, x};
			insert_min_heap(h, e);
		}
	}
}