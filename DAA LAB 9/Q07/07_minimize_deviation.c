// Problem 7: Minimise Deviation in Array
// This program keeps reducing the largest value until the overall spread is minimized.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Max-heap keeps the current largest values so we can repeatedly reduce them.

int heap[1000];
int heapSize = 0;

void pushHeap(int value) {
    int i = heapSize++;
    heap[i] = value;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }
}

int popMax() {
    int maxValue = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heapSize && heap[left] > heap[largest]) largest = left;
        if (right < heapSize && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
    return maxValue;
}

int getMinValue() {
    int minVal = INT_MAX;
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] < minVal) minVal = heap[i];
    }
    return minVal;
}

// Main routine: normalize odd numbers, push values into the heap, and track the minimum deviation.

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        while (arr[i] % 2 != 0) {
            arr[i] *= 2;
        }
        pushHeap(arr[i]);
    }

    int best = INT_MAX;
    while (heapSize > 0) {
        int maxVal = popMax();
        int minVal = getMinValue();
        if (maxVal - minVal < best) best = maxVal - minVal;
        if (maxVal % 2 == 0) {
            int next = maxVal / 2;
            if (next > 0) pushHeap(next);
        } else {
            break;
        }
    }

    printf("Minimum deviation: %d\n", best);
    return 0;
}
