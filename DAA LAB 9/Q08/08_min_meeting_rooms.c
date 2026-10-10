// Problem 8: Minimum Number of Meeting Rooms
// This program checks the maximum overlap among meetings by sorting times and sweeping through them.

#include <stdio.h>
#include <stdlib.h>

// Each meeting stores its start and end time.

typedef struct {
    int start;
    int end;
} Meeting;

int cmpStart(const void *a, const void *b) {
    Meeting *x = (Meeting *)a;
    Meeting *y = (Meeting *)b;
    return x->start - y->start;
}

int cmpInt(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

// Main routine: sort meetings, track room usage, and print the minimum room count.

int main() {
    int n;
    scanf("%d", &n);

    Meeting meetings[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    qsort(meetings, n, sizeof(Meeting), cmpStart);

    int endTimes[1000];
    for (int i = 0; i < n; i++) endTimes[i] = meetings[i].end;
    qsort(endTimes, n, sizeof(int), cmpInt);

    int roomCount = 1;
    int usedRooms = 1;
    int endIndex = 0;
    for (int i = 1; i < n; i++) {
        if (meetings[i].start < endTimes[endIndex]) {
            roomCount++;
            usedRooms = (usedRooms > roomCount) ? usedRooms : roomCount;
        } else {
            endIndex++;
        }
    }

    printf("Minimum rooms required: %d\n", usedRooms);
    return 0;
}
