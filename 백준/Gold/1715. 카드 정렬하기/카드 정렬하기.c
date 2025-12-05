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

void insert_min_heap(HeapType* h, element item) {
	int i = ++h->size;
	while (i != 1 && item.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	element item = h->heap[1];
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;
	while (child <= h->size) {
		if (child < h->size && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	int N, i, x, card1 = 0, card2 = 0;
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		element e = {x};
		insert_min_heap(h, e);
	}

	int result = 0;
	if (h->size >= 2)
		while (h->size) {
			card1 = delete_min_heap(h).key;
			if (h->size >= 1) {
				card2 = delete_min_heap(h).key;
			}
			element new_card = {card1 + card2};
			result += new_card.key;
			if (h->size == 0)
				break;
			insert_min_heap(h, new_card);
			card1 = 0;
			card2 = 0;
		}
	printf("%d\n", result);

	free(h);
	return 0;
}