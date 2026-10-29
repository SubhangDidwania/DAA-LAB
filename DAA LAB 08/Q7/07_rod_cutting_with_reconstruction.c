#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void rodCutting(int price[], int n) {
    int dp[n + 1];
    int choice[n + 1];

    dp[0] = 0;
    for (int len = 1; len <= n; len++) {
        dp[len] = -1;
        choice[len] = -1;
        for (int cut = 1; cut <= len; cut++) {
            int candidate = price[cut] + dp[len - cut];
            if (candidate > dp[len]) {
                dp[len] = candidate;
                choice[len] = cut;
            }
        }
    }

    printf("Maximum revenue: %d\n", dp[n]);
    printf("Optimal pieces: ");
    while (n > 0 && choice[n] != -1) {
        printf("%d ", choice[n]);
        n -= choice[n];
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter rod length: ");
    scanf("%d", &n);

    int price[n + 1];
    printf("Enter price for lengths 1 to %d: \n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    rodCutting(price, n);
    return 0;
}
