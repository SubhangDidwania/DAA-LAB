// Problem 4: Minimum Cost to Connect Sticks
// This program repeatedly merges the two shortest sticks, because that yields the lowest total connection cost.

#include <stdio.h>
#include <stdlib.h>

// Min-heap keeps the available stick lengths sorted from smallest to largest.

int heap[1000];
int heapSize = 0;

void pushHeap(int value) {
    int i = heapSize++;
    heap[i] = value;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap() {
    int minValue = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heapSize && heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;
        if (smallest == i) break;
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
    return minValue;
}

// Main routine: read the lengths, merge the smallest pairs, and compute the minimum total cost.

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushHeap(x);
    }

    long long totalCost = 0;
    while (heapSize > 1) {
        int x = popHeap();
        int y = popHeap();
        int merged = x + y;
        totalCost += merged;
        pushHeap(merged);
    }

    printf("Minimum total cost: %lld\n", totalCost);
    return 0;
}
