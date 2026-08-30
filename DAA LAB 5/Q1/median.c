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
    if (low == high)
        return arr[low];

    int p = partition(arr, low, high);

    if (p == k)
        return arr[p];
    else if (k < p)
        return quickSelect(arr, low, p - 1, k);
    else
        return quickSelect(arr, p + 1, high, k);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], copy[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        copy[i] = arr[i];
    }

    double median;

    if (n % 2 != 0) {
        median = quickSelect(arr, 0, n - 1, n / 2);
    } else {
        int left = quickSelect(arr, 0, n - 1, n / 2 - 1);

        // Restore original array because QuickSelect modifies it
        for (int i = 0; i < n; i++)
            arr[i] = copy[i];

        int right = quickSelect(arr, 0, n - 1, n / 2);

        median = (left + right) / 2.0;
    }

    printf("Median = %.2lf\n", median);

    return 0;
}