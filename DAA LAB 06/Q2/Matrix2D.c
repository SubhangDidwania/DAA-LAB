#include <stdio.h>

void add(int A[][20], int B[][20], int C[][20], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiply(int A[][20], int B[][20], int C[][20], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int isZero(int A[][20], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                return 0;
    return 1;
}

int isSymmetric(int A[][20], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] != A[j][i])
                return 0;
    return 1;
}

void transpose(int A[][20], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

void print(int A[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main() {
    int n, A[20][20], B[20][20], C[20][20];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    
    print(A, n);
    print(B, n);
    
    add(A, B, C, n);
    printf("\nAddition:\n");
    print(C, n);

    multiply(A, B, C, n);
    printf("\nMultiplication:\n");
    print(C, n);

    printf("\nZero matrix: %s\n", isZero(A, n) ? "Yes" : "No");
    printf("Symmetric: %s\n", isSymmetric(A, n) ? "Yes" : "No");

    transpose(A, n);
    printf("\nTranspose of A:\n");
    print(A, n);

    return 0;
}