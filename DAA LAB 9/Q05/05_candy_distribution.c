// Problem 5: Candy Distribution Problem
// This program satisfies both left-to-right and right-to-left rating constraints using a two-pass greedy method.

#include <stdio.h>
#include <stdlib.h>

// Main routine: assign candy counts in two passes and sum the final total.

int main() {
    int n;
    scanf("%d", &n);

    // Ratings of all children in the queue.

int ratings[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
    }

    // Minimum candies allocated to each child while respecting the constraints.

int candies[1000];
    for (int i = 0; i < n; i++) candies[i] = 1;

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) total += candies[i];

    printf("Minimum candies required: %d\n", total);
    return 0;
}
