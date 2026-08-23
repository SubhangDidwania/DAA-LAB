#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type;   // 1 = entry, -1 = exit
} Event;

void merge(Event a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    Event *t = malloc((r - l + 1) * sizeof(Event));

    while (i <= m && j <= r)
        t[k++] = (a[i].time < a[j].time) ? a[i++] : a[j++];

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

    printf("Enter number of people: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Validation FAILED: Number of people must be greater than 0.\n");
        return 1;
    }

    printf("Validation PASSED: Number of people is valid.\n");

    Event *e = malloc(2 * n * sizeof(Event));

    printf("\nEnter entry and exit time for each person:\n");

    for (int i = 0; i < n; i++) {
        int a, b;

        printf("Person %d: ", i + 1);
        scanf("%d %d", &a, &b);

        if (b <= a) {
            printf("Validation FAILED: Exit time must be greater than entry time.\n");
            free(e);
            return 1;
        }

        e[2 * i] = (Event){a, 1};
        e[2 * i + 1] = (Event){b, -1};
    }

    /* Sort all events by time */
    sort(e, 0, 2 * n - 1);

    int current = 0;
    int maximum = 0;
    int maxTime = 0;

    /* Find maximum number of people */
    for (int i = 0; i < 2 * n; i++) {
        current += e[i].type;

        if (current > maximum) {
            maximum = current;
            maxTime = e[i].time;
        }
    }

    printf("\nMaximum people present: %d\n", maximum);
    printf("Time when maximum was reached: %d\n", maxTime);

    free(e);

    return 0;
}