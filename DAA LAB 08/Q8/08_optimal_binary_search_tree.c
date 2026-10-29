#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void optimalBST(int keys[], int p[], int q[], int n) {
    int dp[n + 1][n + 1];
    int root[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        dp[i][i - 1] = q[i - 1];
        dp[i + 1][i] = q[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = 999999;
            for (int r = i; r <= j; r++) {
                int cost = dp[i][r - 1] + dp[r + 1][j] + (p[r] + q[r] + q[r - 1]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum expected cost: %d\n", dp[1][n]);
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    int keys[n + 1], p[n + 1], q[n + 1];
    printf("Enter keys: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &keys[i]);
    }
    printf("Enter probabilities p[1..%d]: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter probabilities q[0..%d]: ", n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &q[i]);
    }

    optimalBST(keys, p, q, n);
    return 0;
}
