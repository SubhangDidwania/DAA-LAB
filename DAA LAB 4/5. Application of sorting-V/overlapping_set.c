#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Interval;

void merge(Interval a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    Interval *t = malloc((r - l + 1) * sizeof(Interval));

    while (i <= m && j <= r)
        t[k++] = (a[i].x < a[j].x) ? a[i++] : a[j++];

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = t[k++];

    free(t);
}

void sort(Interval a[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    /* Validation */
    if (n <= 0) {
        printf("Validation FAILED: Number of intervals must be greater than 0.\n");
        return 1;
    }

    printf("Validation PASSED: Number of intervals is valid.\n");

    Interval *a = malloc(n * sizeof(Interval));
    Interval *result = malloc(n * sizeof(Interval));

    printf("\nEnter intervals (x y):\n");

    for (int i = 0; i < n; i++) {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &a[i].x, &a[i].y);

        if (a[i].x > a[i].y) {
            printf("Validation FAILED: x must be <= y.\n");
            free(a);
            free(result);
            return 1;
        }
    }

    /* Sort by starting point */
    sort(a, 0, n - 1);

    /* Merge overlapping intervals */
    int count = 0;

    result[count++] = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i].x <= result[count - 1].y) {
            if (a[i].y > result[count - 1].y)
                result[count - 1].y = a[i].y;
        }
        else {
            result[count++] = a[i];
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++)
        printf("(%d, %d) ", result[i].x, result[i].y);

    printf("\n");

    free(a);
    free(result);

    return 0;
}