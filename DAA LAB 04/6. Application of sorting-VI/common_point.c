#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int point;
    int type;       // 1 = start, -1 = end
} Event;

void merge(Event a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    Event *t = malloc((r - l + 1) * sizeof(Event));

    while (i <= m && j <= r) {
        if (a[i].point < a[j].point ||
           (a[i].point == a[j].point && a[i].type > a[j].type))
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = t[k++];

    free(t);
}

void sort(Event a[], int l, int r)
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

    Event *e = malloc(2 * n * sizeof(Event));

    printf("\nEnter intervals (left right):\n");

    for (int i = 0; i < n; i++) {
        int l, r;

        printf("Interval %d: ", i + 1);
        scanf("%d %d", &l, &r);

        if (l > r) {
            printf("Validation FAILED: left endpoint must be <= right endpoint.\n");
            free(e);
            return 1;
        }

        e[2 * i] = (Event){l, 1};   // start
        e[2 * i + 1] = (Event){r, -1}; // end
    }

    /* Sort events */
    sort(e, 0, 2 * n - 1);

    int current = 0;
    int maximum = 0;
    int p = 0;

    /* Sweep through events */
    for (int i = 0; i < 2 * n; i++) {

        current += e[i].type;

        if (current > maximum) {
            maximum = current;
            p = e[i].point;
        }
    }

    printf("\nPoint with maximum overlap: %d\n", p);
    printf("Maximum number of intervals: %d\n", maximum);

    free(e);

    return 0;
}