#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int editDistance(char *A, char *B) {
    int m = strlen(A);
    int n = strlen(B);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    printf("Minimum edit distance: %d\n", dp[m][n]);

    int i = m, j = n;
    printf("Traceback path:\n");
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && A[i - 1] == B[j - 1]) {
            printf("Match: %c\n", A[i - 1]);
            i--;
            j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("Replace '%c' with '%c'\n", A[i - 1], B[j - 1]);
            i--;
            j--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert '%c'\n", B[j - 1]);
            j--;
        } else {
            printf("Delete '%c'\n", A[i - 1]);
            i--;
        }
    }

    return dp[m][n];
}

int main() {
    char A[100], B[100];
    printf("Enter first string: ");
    scanf("%s", A);
    printf("Enter second string: ");
    scanf("%s", B);

    editDistance(A, B);
    return 0;
}
