// Problem 3: Minimum Initial Fuel (Reverse Greedy)
// This program decides how many refueling stops are needed by picking the largest fuel amount among reachable stations.

#include <stdio.h>
#include <stdlib.h>

// Each station stores its distance from the start and the amount of fuel it provides.

typedef struct {
    int distance;
    int fuel;
} Station;

int compare(const void *a, const void *b) {
    Station *x = (Station *)a;
    Station *y = (Station *)b;
    return x->distance - y->distance;
}

// Max-heap stores fuel values collected from all reachable stations.

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

int popHeap() {
    int root = heap[0];
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
    return root;
}

// Main routine: sort stations, greedily collect fuel, and check whether the target can be reached.

int main() {
    int n, F, D;
    scanf("%d %d %d", &n, &F, &D);

    Station stations[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &stations[i].distance, &stations[i].fuel);
    }

    qsort(stations, n, sizeof(Station), compare);

    int currentFuel = F;
    int i = 0;
    int stops = 0;

    while (currentFuel < D) {
        while (i < n && stations[i].distance <= currentFuel) {
            pushHeap(stations[i].fuel);
            i++;
        }

        if (heapSize == 0) {
            printf("Impossible to reach target\n");
            return 0;
        }

        currentFuel += popHeap();
        stops++;
    }

    printf("Minimum refuelling stops: %d\n", stops);
    return 0;
}
