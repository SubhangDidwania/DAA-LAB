#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumIncreasingSubsequence(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    int best = dp[0];
    for (int i = 1; i < n; i++) {
        best = max(best, dp[i]);
    }
    return best;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Maximum sum of an increasing subsequence: %d\n", maxSumIncreasingSubsequence(arr, n));
    return 0;
}
