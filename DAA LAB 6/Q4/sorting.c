#include <stdio.h>

long long cost = 0;

void reversePart(int a[], int l, int r) {
    cost += r - l + 1;

    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

void rotate(int a[], int l, int m, int r) {
    if (l >= m || m >= r)
        return;

    reversePart(a, l, m - 1);
    reversePart(a, m, r - 1);
    reversePart(a, l, r - 1);
}

/*
   Stable partition:
   elements < x come before elements >= x
*/
void partitionArray(int a[], int l, int r, int x) {
    if (r - l <= 1)
        return;

    int m = (l + r) / 2;

    partitionArray(a, l, m, x);
    partitionArray(a, m, r, x);

    int left = l;

    while (left < m && a[left] < x)
        left++;

    int mid = m;

    while (mid < r && a[mid] < x)
        mid++;

    if (left < m && m < mid)
        rotate(a, left, m, mid);
}

/* Sort by recursively dividing value range */
void sort(int a[], int l, int r, int low, int high) {
    if (r - l <= 1)
        return;

    if (low == high)
        return;

    int mid = (low + high) / 2;

    partitionArray(a, l, r, mid + 1);

    int split = l;

    while (split < r && a[split] <= mid)
        split++;

    sort(a, l, split, low, mid);
    sort(a, split, r, mid + 1, high);
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter permutation: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, 0, n, 1, n);

    printf("Sorted permutation: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal reversal cost = %lld\n", cost);

    return 0;
}