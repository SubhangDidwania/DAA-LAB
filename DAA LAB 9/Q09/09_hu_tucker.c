// Problem 9: Hu-Tucker Greedy Simulation
// This program approximates the ordered merge process by minimizing weighted interval cost over the sequence.

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Main routine: read the weights, compute the interval DP cost, and print the minimum weighted depth.

int main() {
    int n;
    scanf("%d", &n);

    int w[100];
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    double dp[100][100];
    int prefix[100] = {0};

    for (int i = 0; i < n; i++) {
        prefix[i] = (i == 0) ? w[i] : prefix[i - 1] + w[i];
    }

    for (int i = 0; i < n; i++) dp[i][i] = 0.0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = DBL_MAX;
            for (int k = i; k < j; k++) {
                double cost = dp[i][k] + dp[k + 1][j] + (prefix[j] - (i > 0 ? prefix[i - 1] : 0));
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum weighted depth: %.0f\n", dp[0][n - 1]);
    return 0;
}
