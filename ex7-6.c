#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int heapSize;
    int heapArr[MAX_HEAP_SIZE];
} heapType;

heapType* createHeap(void) {
    heapType* heap = (heapType*)malloc(sizeof(heapType));
    if (heap == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    heap->heapSize = 0;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(heapType* heap, int item) {
    if (heap == NULL || heap->heapSize + 1 >= MAX_HEAP_SIZE) {
        fprintf(stderr, "Heap is full or invalid\n");
        return;
    }

    heap->heapSize++;
    int i = heap->heapSize;
    heap->heapArr[i] = item;

    while (i > 1 && heap->heapArr[i] > heap->heapArr[i / 2]) {
        swap(&heap->heapArr[i], &heap->heapArr[i / 2]);
        i /= 2;
    }
}

int deleteHeap(heapType* heap) {
    if (heap == NULL || heap->heapSize == 0) {
        fprintf(stderr, "Heap is empty or invalid\n");
        return -1;
    }

    int removed = heap->heapArr[1];
    heap->heapArr[1] = heap->heapArr[heap->heapSize];
    heap->heapSize--;

    int parent = 1;
    while (1) {
        int left = parent * 2;
        int right = left + 1;
        int child = parent;

        if (left <= heap->heapSize && heap->heapArr[left] > heap->heapArr[child]) {
            child = left;
        }
        if (right <= heap->heapSize && heap->heapArr[right] > heap->heapArr[child]) {
            child = right;
        }
        if (child == parent) break;

        swap(&heap->heapArr[parent], &heap->heapArr[child]);
        parent = child;
    }

    return removed;
}

void printHeap(heapType* heap) {
    if (heap == NULL) {
        return;
    }
    printf("Heap elements (1..%d):", heap->heapSize);
    for (int i = 1; i <= heap->heapSize; i++) {
        printf(" %d", heap->heapArr[i]);
    }
    printf("\n");
}

int main(void) {
    heapType* heap = createHeap();
    if (heap == NULL) {
        return 1;
    }

    insertHeap(heap, 10);
    insertHeap(heap, 45);
    insertHeap(heap, 19);
    insertHeap(heap, 11);
    insertHeap(heap, 96);

    printHeap(heap);

    int n = heap->heapSize;
    for (int i = 1; i <= n; i++) {
        int item = deleteHeap(heap);
        printf("\n delete : [%d]", item);
    }
    printf("\n");

    free(heap);
    return 0;
}
