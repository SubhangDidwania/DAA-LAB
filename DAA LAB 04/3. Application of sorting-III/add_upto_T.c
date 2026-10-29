#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *t = malloc((r - l + 1) * sizeof(int));

    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m)
        t[k++] = a[i++];

    while (j <= r)
        t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = t[k++];

    free(t);
}

void sort(int a[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int search(int a[], int l, int r, int x)
{
    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m] == x)
            return 1;

        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return 0;
}

int findK(int a[], int n, int k, int start, int T)
{
    if (k == 1)
        return search(a, start, n - 1, T);

    for (int i = start; i <= n - k; i++) {
        if (findK(a, n, k - 1, i + 1, T - a[i]))
            return 1;
    }

    return 0;
}

int main()
{
    int n, k, T;

    printf("Enter set size: ");
    scanf("%d", &n);

    /* Set size validation */
    if (n <= 0) {
        printf("Validation FAILED: Set size must be greater than 0.\n");
        return 1;
    }

    printf("Validation PASSED: Set size is valid.\n");

    printf("Enter k: ");
    scanf("%d", &k);

    /* Validate k */
    if (k <= 0 || k > n) {
        printf("Validation FAILED: k must be between 1 and %d.\n", n);
        return 1;
    }

    int *S = malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter T: ");
    scanf("%d", &T);

    /* Sort the set */
    sort(S, 0, n - 1);

    printf("Sorted set: ");
    for (int i = 0; i < n; i++)
        printf("%d ", S[i]);

    printf("\n");

    /* Test whether k elements add up to T */
    if (findK(S, n, k, 0, T))
        printf("Validation PASSED: %d elements add up to %d.\n", k, T);
    else
        printf("No combination of %d elements adds up to %d.\n", k, T);

    free(S);

    return 0;
}