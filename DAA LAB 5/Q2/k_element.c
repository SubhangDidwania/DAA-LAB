#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {

        int p = partition(arr, low, high);

        if (p == k)
            return arr[p];

        if (k < p)
            return quickSelect(arr, low, p - 1, k);

        return quickSelect(arr, p + 1, high, k);
    }

    return -1;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of K\n");
        return 0;
    }

    int result = quickSelect(arr, 0, n - 1, k - 1);

    printf("%d-th smallest element = %d\n", k, result);

    return 0;
}