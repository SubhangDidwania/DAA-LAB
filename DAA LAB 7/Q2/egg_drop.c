#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int eggs, floors;
    printf("Enter the number of eggs and floors: ");
    fflush(stdout);
    if (scanf("%d %d", &eggs, &floors) != 2 || eggs < 1 || floors < 0) {
        fprintf(stderr, "Input: positive eggs followed by non-negative floors.\n");
        return 1;
    }

    int **dp = malloc((size_t)(eggs + 1) * sizeof(*dp));
    if (!dp) return 1;
    for (int e = 0; e <= eggs; ++e) {
        dp[e] = calloc((size_t)(floors + 1), sizeof(**dp));
        if (!dp[e]) return 1;
    }

    for (int f = 1; f <= floors; ++f) dp[1][f] = f;
    for (int e = 2; e <= eggs; ++e) {
        for (int f = 1; f <= floors; ++f) {
            dp[e][f] = f;
            for (int drop = 1; drop <= f; ++drop) {
                int worst = 1 + (dp[e - 1][drop - 1] > dp[e][f - drop]
                    ? dp[e - 1][drop - 1] : dp[e][f - drop]);
                if (worst < dp[e][f]) dp[e][f] = worst;
            }
        }
    }

    printf("Minimum droppings: %d\n", dp[eggs][floors]);
    for (int e = 0; e <= eggs; ++e) free(dp[e]);
    free(dp);
    return 0;
}