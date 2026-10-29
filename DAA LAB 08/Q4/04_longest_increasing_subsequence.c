#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lisLength(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, dp[i]);
    }

    return best;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Length of LIS: %d\n", lisLength(arr, n));
    return 0;
}
