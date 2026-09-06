#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double r, i;
} Complex;

Complex add(Complex a, Complex b) {
    return (Complex){a.r + b.r, a.i + b.i};
}

Complex sub(Complex a, Complex b) {
    return (Complex){a.r - b.r, a.i - b.i};
}

Complex mul(Complex a, Complex b) {
    return (Complex){
        a.r*b.r - a.i*b.i,
        a.r*b.i + a.i*b.r
    };
}

void fft(Complex a[], int n, int inv) {
    if (n == 1) return;

    Complex even[n/2], odd[n/2];

    for (int i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i] = a[2*i+1];
    }

    fft(even, n/2, inv);
    fft(odd, n/2, inv);

    double ang = 2 * M_PI / n * inv;
    Complex w = {1, 0};
    Complex wn = {cos(ang), sin(ang)};

    for (int k = 0; k < n/2; k++) {
        Complex t = mul(w, odd[k]);

        a[k] = add(even[k], t);
        a[k+n/2] = sub(even[k], t);

        w = mul(w, wn);
    }
}

void convolution(double A[], double B[], int m, int n) {
    int size = 1;

    while (size < m + n - 1)
        size *= 2;

    Complex a[size], b[size];

    for (int i = 0; i < size; i++) {
        a[i].r = (i < m) ? A[i] : 0;
        a[i].i = 0;

        b[i].r = (i < n) ? B[i] : 0;
        b[i].i = 0;
    }

    fft(a, size, 1);
    fft(b, size, 1);

    for (int i = 0; i < size; i++)
        a[i] = mul(a[i], b[i]);

    fft(a, size, -1);

    printf("Convolution:\n");

    for (int i = 0; i < m+n-1; i++)
        printf("%.0lf ", a[i].r / size);

    printf("\n");
}

int main() {
    int m, n;

    printf("Enter sizes m and n: ");
    scanf("%d %d", &m, &n);

    double A[m], B[n];

    printf("Enter A: ");
    for (int i = 0; i < m; i++)
        scanf("%lf", &A[i]);

    printf("Enter B: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i]);

    convolution(A, B, m, n);

    return 0;
}