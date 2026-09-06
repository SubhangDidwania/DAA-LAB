#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void maxSecond(int a[], int n) {
    int max = a[0], second = -2147483648;

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            second = max;
            max = a[i];
        } else if (a[i] > second && a[i] != max)
            second = a[i];
    }

    printf("Maximum = %d\nSecond Largest = %d\n", max, second);
}

void meanSD(int a[], int n) {
    double sum = 0, mean, sd = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for (int i = 0; i < n; i++)
        sd += (a[i] - mean) * (a[i] - mean);

    sd = sqrt(sd / n);

    printf("Mean = %.2lf\nStandard Deviation = %.2lf\n", mean, sd);
}

void median(int a[], int n) {
    int b[n];

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    // Sorting
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (b[j] > b[j + 1]) {
                int t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }

    if (n % 2)
        printf("Median = %d\n", b[n / 2]);
    else
        printf("Median = %.2lf\n", (b[n/2] + b[n/2-1]) / 2.0);
}

void mode(int a[], int n) {
    int best = a[0], bestCount = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++)
            if (a[i] == a[j])
                count++;

        if (count > bestCount) {
            bestCount = count;
            best = a[i];
        }
    }

    printf("Mode = %d\n", best);
}

void removeDuplicates(int a[], int *n) {
    int k = 0;

    for (int i = 0; i < *n; i++) {
        int found = 0;

        for (int j = 0; j < k; j++)
            if (a[i] == a[j])
                found = 1;

        if (!found)
            a[k++] = a[i];
    }

    *n = k;
}

void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}

void partition(int a[], int n, int pivot) {
    int i = 0, j = n - 1;

    while (i <= j) {
        while (i < n && a[i] >= pivot) i++;
        while (j >= 0 && a[j] < pivot) j--;

        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    maxSecond(a, n);
    meanSD(a, n);
    median(a, n);
    mode(a, n);

    removeDuplicates(a, &n);

    printf("After removing duplicates: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    reverse(a, n);

    printf("\nAfter reversing: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}