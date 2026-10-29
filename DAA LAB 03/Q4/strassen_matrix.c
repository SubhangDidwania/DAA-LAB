#include <stdio.h>
#include <stdlib.h>

/*
 * Add two matrices
 */
void addMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/*
 * Subtract matrix B from matrix A
 */
void subtractMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/*
 * Allocate an n x n matrix
 */
int **createMatrix(int n) {

    int **matrix = malloc(n * sizeof(int *));

    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {

        matrix[i] = calloc(n, sizeof(int));

        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    return matrix;
}

/*
 * Free an n x n matrix
 */
void freeMatrix(int **matrix, int n) {

    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

/*
 * Strassen Matrix Multiplication
 */
void strassen(int **A, int **B, int **C, int n) {

    /*
     * Base case
     */
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    /*
     * Create submatrices
     */
    int **A11 = createMatrix(k);
    int **A12 = createMatrix(k);
    int **A21 = createMatrix(k);
    int **A22 = createMatrix(k);

    int **B11 = createMatrix(k);
    int **B12 = createMatrix(k);
    int **B21 = createMatrix(k);
    int **B22 = createMatrix(k);

    /*
     * Temporary matrices
     */
    int **M1 = createMatrix(k);
    int **M2 = createMatrix(k);
    int **M3 = createMatrix(k);
    int **M4 = createMatrix(k);
    int **M5 = createMatrix(k);
    int **M6 = createMatrix(k);
    int **M7 = createMatrix(k);

    int **X = createMatrix(k);
    int **Y = createMatrix(k);

    /*
     * Divide A and B into four blocks
     */
    for (int i = 0; i < k; i++) {

        for (int j = 0; j < k; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    /*
     * M1 = (A11 + A22)(B11 + B22)
     */
    addMatrix(A11, A22, X, k);
    addMatrix(B11, B22, Y, k);

    strassen(X, Y, M1, k);

    /*
     * M2 = (A21 + A22)B11
     */
    addMatrix(A21, A22, X, k);

    strassen(X, B11, M2, k);

    /*
     * M3 = A11(B12 - B22)
     */
    subtractMatrix(B12, B22, Y, k);

    strassen(A11, Y, M3, k);

    /*
     * M4 = A22(B21 - B11)
     */
    subtractMatrix(B21, B11, Y, k);

    strassen(A22, Y, M4, k);

    /*
     * M5 = (A11 + A12)B22
     */
    addMatrix(A11, A12, X, k);

    strassen(X, B22, M5, k);

    /*
     * M6 = (A21 - A11)(B11 + B12)
     */
    subtractMatrix(A21, A11, X, k);
    addMatrix(B11, B12, Y, k);

    strassen(X, Y, M6, k);

    /*
     * M7 = (A12 - A22)(B21 + B22)
     */
    subtractMatrix(A12, A22, X, k);
    addMatrix(B21, B22, Y, k);

    strassen(X, Y, M7, k);

    /*
     * Calculate C11
     *
     * C11 = M1 + M4 - M5 + M7
     */
    for (int i = 0; i < k; i++) {

        for (int j = 0; j < k; j++) {

            C[i][j] =
                M1[i][j]
                + M4[i][j]
                - M5[i][j]
                + M7[i][j];

            /*
             * C12 = M3 + M5
             */
            C[i][j + k] =
                M3[i][j]
                + M5[i][j];

            /*
             * C21 = M2 + M4
             */
            C[i + k][j] =
                M2[i][j]
                + M4[i][j];

            /*
             * C22 = M1 - M2 + M3 + M6
             */
            C[i + k][j + k] =
                M1[i][j]
                - M2[i][j]
                + M3[i][j]
                + M6[i][j];
        }
    }

    /*
     * Free memory
     */
    freeMatrix(A11, k);
    freeMatrix(A12, k);
    freeMatrix(A21, k);
    freeMatrix(A22, k);

    freeMatrix(B11, k);
    freeMatrix(B12, k);
    freeMatrix(B21, k);
    freeMatrix(B22, k);

    freeMatrix(M1, k);
    freeMatrix(M2, k);
    freeMatrix(M3, k);
    freeMatrix(M4, k);
    freeMatrix(M5, k);
    freeMatrix(M6, k);
    freeMatrix(M7, k);

    freeMatrix(X, k);
    freeMatrix(Y, k);
}

/*
 * Find the next power of 2 >= n
 */
int nextPowerOfTwo(int n) {

    int power = 1;

    while (power < n)
        power *= 2;

    return power;
}

/*
 * Main function
 */
int main() {

    int n;

    printf("Enter size of square matrices: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    /*
     * Find suitable power of 2.
     */
    int size = nextPowerOfTwo(n);

    /*
     * Create original matrices
     */
    int **A = createMatrix(n);
    int **B = createMatrix(n);

    /*
     * Create padded matrices
     */
    int **Ap = createMatrix(size);
    int **Bp = createMatrix(size);
    int **Cp = createMatrix(size);

    /*
     * Input matrix A
     */
    printf("\nEnter matrix A:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            scanf("%d", &A[i][j]);

            Ap[i][j] = A[i][j];
        }
    }

    /*
     * Input matrix B
     */
    printf("\nEnter matrix B:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            scanf("%d", &B[i][j]);

            Bp[i][j] = B[i][j];
        }
    }

    /*
     * Perform Strassen multiplication.
     */
    strassen(Ap, Bp, Cp, size);

    /*
     * Print original matrices
     */
    printf("\nMatrix A:\n");
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("%d ", A[i][j]);
        }

        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("%d ", B[i][j]);
        }

        printf("\n");
    }

    /*
     * Print only the original n x n result.
     */
    printf("\nResult of A x B:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("%d ", Cp[i][j]);
        }

        printf("\n");
    }

    /*
     * Free all matrices.
     */
    freeMatrix(A, n);
    freeMatrix(B, n);

    freeMatrix(Ap, size);
    freeMatrix(Bp, size);
    freeMatrix(Cp, size);

    return 0;
}