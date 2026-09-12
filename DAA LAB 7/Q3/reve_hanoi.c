#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

static int three[21];
static int four[21];
static int split[64];

static void hanoi3(int disks, char from, char to, char spare) {
    if (!disks) return;
    hanoi3(disks - 1, from, spare, to);
    printf("Move disk from %c to %c\n", from, to);
    hanoi3(disks - 1, spare, to, from);
}

static void hanoi4(int disks, char from, char to, char spare1, char spare2) {
    if (!disks) return;
    int top = split[disks];
    hanoi4(top, from, spare1, to, spare2);
    hanoi3(disks - top, from, to, spare2);
    hanoi4(top, spare1, to, from, spare2);
}

int main(void) {
    int disks;
    printf("Enter the number of disks: ");
    fflush(stdout);
    if (scanf("%d", &disks) != 1 || disks < 1 || disks > 20) {
        fprintf(stderr, "Enter a disk count from 1 to 20.\n");
        return 1;
    }

    three[0] = four[0] = 0;
    three[1] = 1;
    four[1] = 1;
    for (int n = 2; n <= disks; ++n) {
        three[n] = 2 * three[n - 1] + 1;
        four[n] = INT_MAX;
        for (int k = 1; k < n; ++k) {
            int candidate = 2 * four[k] + three[n - k];
            if (candidate < four[n]) {
                four[n] = candidate;
                split[n] = k;
            }
        }
    }

    printf("Minimum moves (Frame-Stewart): %d\n", four[disks]);
    if (disks <= 8) hanoi4(disks, 'A', 'D', 'B', 'C');
    return 0;
}