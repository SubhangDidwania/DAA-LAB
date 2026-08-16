#include <stdio.h>

/* Print the array */
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Selection Sort */
void selectionSort(int A[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int min = i;

        /* Find minimum in unsorted part */
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }

        /* Swap minimum with A[i] */
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        /* Print current step */
        printf("Step %d: ", i + 1);
        printArray(A, n);
    }
}

int main() {

    int n, A[100];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("\nInitial array: ");
    printArray(A, n);

    printf("\nSorting steps:\n");
    selectionSort(A, n);

    printf("\nFinal sorted array: ");
    printArray(A, n);

    return 0;
}