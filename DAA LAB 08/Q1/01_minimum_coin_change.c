#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];
    for (int i = 0; i <= V; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int amount = 1; amount <= V; amount++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount && dp[amount - coins[i]] != INT_MAX) {
                int candidate = dp[amount - coins[i]] + 1;
                if (candidate < dp[amount]) {
                    dp[amount] = candidate;
                }
            }
        }
    }

    return (dp[V] == INT_MAX) ? -1 : dp[V];
}

int main() {
    int n, V;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter %d coin denominations: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &V);

    int result = minCoins(coins, n, V);
    if (result == -1) {
        printf("Minimum number of coins required: not possible\n");
    } else {
        printf("Minimum number of coins required: %d\n", result);
    }

    return 0;
}
