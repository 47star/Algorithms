#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Heap {
    short* data;
    unsigned int size;
    bool (*comparation)(Heap *heap, short a, short b);
};

void push(Heap *heap, short data) {
    heap->data[++heap->size] = data;

    unsigned int i = heap->size, p = i / 2;

    while (p && heap->comparation(heap, heap->data[i], heap->data[p])) {
        swap(heap->data[p], heap->data[i]);
        i = p;
        p = i / 2;
    }
}

short pop(Heap *heap) {
    short temp = heap->data[1];
    heap->data[1] = heap->data[heap->size--];
    
    unsigned int i = 1, c = 2;

    while (c <= heap->size) {
        if (c + 2 <= heap->size && heap->comparation(heap, heap->data[c], heap->data[c + 1]))
            c++;
        if (heap->comparation(heap, heap->data[i], heap->data[c])) {
            swap(heap->data[i], heap->data[c]);
            i = c;
            c = i / 2;
        } else
            break;
    }

    return temp;
}

bool minHeapComparation(Heap *heap, short a, short b) {
    return a < b;
}

bool maxHeapComparation(Heap *heap, short a, short b) {
    return b < a;
}

int main() {
    unsigned int n, i;
    short a, min, max;
    scanf("%u", &n);

    Heap maxq = Heap { (short*)malloc((n / 2 + 2) * sizeof(short)), 0, maxHeapComparation };
    Heap minq = Heap { (short*)malloc((n / 2 + 1) * sizeof(short)), 0, minHeapComparation };

    for (i = 0; i < n; i++) {
        scanf("%hd", &a);

        if (maxq.size == minq.size)
            push(&maxq, a);
        else
            push(&minq, a);
        
        if (minq.size != 0 && minq.data[1] < maxq.data[1]) {
            max = pop(&maxq);
            min = pop(&minq);
            push(&maxq, min);
            push(&minq, max);
        }
        
        printf("%hd\n", maxq.data[1]);
    }
	
	return 0;
}