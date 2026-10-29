#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *t = malloc((r - l + 1) * sizeof(int));

    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

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

int search(int a[], int n, int x)
{
    int l = 0, r = n - 1;

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

int main()
{
    int n, x, found = 0;

    printf("Enter set size: ");
    scanf("%d", &n);

    /* Validation test for set size */
    if (n <= 0) {
        printf("Validation FAILED: Set size must be greater than 0.\n");
        return 1;
    }

    printf("Validation PASSED: Set size is valid.\n");

    int *S1 = malloc(n * sizeof(int));
    int *S2 = malloc(n * sizeof(int));

    printf("Enter S1: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter S2: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    sort(S2, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (search(S2, n, x - S1[i])) {
            printf("Pair found: %d + %d = %d\n",
                   S1[i], x - S1[i], x);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No pair found.\n");

    free(S1);
    free(S2);

    return 0;
}