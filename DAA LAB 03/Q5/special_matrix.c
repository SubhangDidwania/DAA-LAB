#include <stdio.h>

#define MAX 64

/* Add two matrices */
void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

/* Subtract B from A */
void sub(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

/* Multiply special-pattern matrices */
void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {

    /* Base case */
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];
    int P[MAX][MAX], Q[MAX][MAX];
    int R[MAX][MAX], S[MAX][MAX];
    int X[MAX][MAX], Y[MAX][MAX];

    /* Extract the two unique blocks */
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }

    /* P=A1+A2, Q=A1-A2 */
    add(A1, A2, P, k);
    sub(A1, A2, Q, k);

    /* R=B1+B2, S=B1-B2 */
    add(B1, B2, R, k);
    sub(B1, B2, S, k);

    /* Two recursive multiplications */
    multiply(P, R, X, k);
    multiply(Q, S, Y, k);

    /* C1=(X+Y)/2, C2=(X-Y)/2 */
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] =
                (X[i][j] + Y[i][j]) / 2;

            C[i][j + k] =
                (X[i][j] - Y[i][j]) / 2;

            /* Copy the symmetric blocks */
            C[i + k][j] =
                C[i][j + k];

            C[i + k][j + k] =
                C[i][j];
        }
}

int main() {

    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

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


    /* Print original matrices */
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    /* Perform multiplication */
    multiply(A, B, C, n);

    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}