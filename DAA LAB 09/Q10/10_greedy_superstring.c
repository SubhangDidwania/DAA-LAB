// Problem 10: Greedy Superstring Conjecture
// This program merges strings with the largest suffix-prefix overlap until one superstring remains.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compute how many characters overlap between the end of one string and the beginning of another.

int overlap(const char *a, const char *b) {
    int lenA = (int)strlen(a);
    int lenB = (int)strlen(b);
    int best = 0;
    for (int k = 1; k <= lenA && k <= lenB; k++) {
        if (strncmp(a + lenA - k, b, k) == 0) {
            best = k;
        }
    }
    return best;
}

void mergeStrings(char *result, const char *a, const char *b) {
    int ov = overlap(a, b);
    strcpy(result, a);
    strcat(result, b + ov);
}

// Main routine: repeatedly merge the best pair and print the greedy superstring.

int main() {
    int n;
    scanf("%d", &n);

    char strings[100][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    while (n > 1) {
        int bestI = 0, bestJ = 1;
        int bestOverlap = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int ov = overlap(strings[i], strings[j]);
                if (ov > bestOverlap) {
                    bestOverlap = ov;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        char merged[200];
        mergeStrings(merged, strings[bestI], strings[bestJ]);

        strcpy(strings[bestI], merged);
        for (int i = bestJ; i < n - 1; i++) {
            strcpy(strings[i], strings[i + 1]);
        }
        n--;
    }

    printf("Greedy superstring: %s\n", strings[0]);
    return 0;
}
