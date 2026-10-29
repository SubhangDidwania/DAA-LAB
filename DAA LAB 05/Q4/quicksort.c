#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    FILE *fp;

    srand(time(NULL));

    /* Generate random numbers and store in file */

    fp = fopen("input.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int num = rand() % 1000;
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    /* Read elements from file */

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    printf("\nOriginal elements:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Quick Sort */

    quickSort(arr, 0, n - 1);

    printf("\n\nSorted elements:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Store sorted elements */

    fp = fopen("sorted.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);

    fclose(fp);

    printf("\n\nSorted elements saved in sorted.txt\n");

    return 0;
}