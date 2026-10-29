#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int binarySearch(int a[], int n, int x, int *comparisons) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (a[mid] == x)
            return mid;

        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int ternarySearch(int a[], int n, int x, int *comparisons) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        (*comparisons)++;

        if (a[mid1] == x)
            return mid1;

        (*comparisons)++;

        if (a[mid2] == x)
            return mid2;

        if (x < a[mid1]) {
            high = mid1 - 1;
        }
        else if (x > a[mid2]) {
            low = mid2 + 1;
        }
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main() {

    int testSizes[] = {
        10,
        20,
        50,
        100,
        200,
        500,
        1000,
        2000,
        5000,
        10000,
        20000,
        50000,
        100000
    };

    int numberOfTests =
        sizeof(testSizes) / sizeof(testSizes[0]);

    int *a = malloc(MAX_N * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    FILE *data = fopen("search_comparison.dat", "w");

    if (data == NULL) {
        printf("Error creating data file.\n");
        free(a);
        return 1;
    }

    fprintf(data,
            "# n Binary_Comparisons Ternary_Comparisons\n");

    printf("\n");
    printf("Binary Search vs Ternary Search\n");
    printf("============================================\n");

    printf("%-10s %-20s %-20s\n",
           "n",
           "Binary",
           "Ternary");

    printf("--------------------------------------------\n");

    for (int t = 0; t < numberOfTests; t++) {

        int n = testSizes[t];

        /*
         * Generate a sorted array:
         * 1, 2, 3, ..., n
         */
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        /*
         * Search for the last element.
         * This gives a useful worst-case-style
         * experiment.
         */
        int x = n;

        int binaryComparisons = 0;
        int ternaryComparisons = 0;

        binarySearch(
            a,
            n,
            x,
            &binaryComparisons
        );

        ternarySearch(
            a,
            n,
            x,
            &ternaryComparisons
        );

        /*
         * Save data for Gnuplot.
         */
        fprintf(data,
                "%d %d %d\n",
                n,
                binaryComparisons,
                ternaryComparisons);

        printf("%-10d %-20d %-20d\n",
               n,
               binaryComparisons,
               ternaryComparisons);
    }

    fclose(data);
    free(a);

    printf("\nData successfully saved to:\n");
    printf("search_comparison.dat\n");

    return 0;
}