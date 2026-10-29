#include <stdio.h>

void findMinMax(int a[], int n,
                int *min,
                int *max,
                int *comparisons) {

    int i;

    /*
     * If there is only one element,
     * it is both minimum and maximum.
     */
    if (n == 1) {
        *min = *max = a[0];
        return;
    }

    /*
     * Handle the first pair.
     */
    if (a[0] < a[1]) {
        *min = a[0];
        *max = a[1];
    } else {
        *min = a[1];
        *max = a[0];
    }

    (*comparisons)++;

    i = 2;

    /*
     * Process remaining elements in pairs.
     */
    while (i + 1 < n) {

        int localMin;
        int localMax;

        /*
         * Compare the two elements in the pair.
         */
        (*comparisons)++;

        if (a[i] < a[i + 1]) {
            localMin = a[i];
            localMax = a[i + 1];
        } else {
            localMin = a[i + 1];
            localMax = a[i];
        }

        /*
         * Compare local minimum with global minimum.
         */
        (*comparisons)++;

        if (localMin < *min)
            *min = localMin;

        /*
         * Compare local maximum with global maximum.
         */
        (*comparisons)++;

        if (localMax > *max)
            *max = localMax;

        i += 2;
    }

    /*
     * If n is odd, process the last element.
     */
    if (i < n) {

        (*comparisons)++;

        if (a[i] < *min)
            *min = a[i];

        (*comparisons)++;

        if (a[i] > *max)
            *max = a[i];
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int min, max;
    int comparisons = 0;

    findMinMax(
        a,
        n,
        &min,
        &max,
        &comparisons
    );

    printf("\nMinimum = %d\n", min);
    printf("Maximum = %d\n", max);

    printf("Number of comparisons = %d\n",
           comparisons);

    printf("3n/2 = %.1f\n", 1.5 * n);

    return 0;
}