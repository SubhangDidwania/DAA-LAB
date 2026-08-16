# Matrix Multiplication using Divide and Conquer (Strassen's Method)

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CSE-B), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

Write a C program to multiply two square matrices of size `n × n` using
**Strassen's algorithm**, a divide-and-conquer technique that reduces the
number of recursive multiplications needed compared to the standard
`O(n^3)` approach.

## Approach (Divide and Conquer)

1. **Divide** each `n × n` input matrix into four `n/2 × n/2` sub-matrices.
2. Compute **7** products (instead of the 8 required by the naive
   block-multiplication approach) using Strassen's combinations:

   ```
   M1 = (A11 + A22) * (B11 + B22)
   M2 = (A21 + A22) * B11
   M3 = A11 * (B12 - B22)
   M4 = A22 * (B21 - B11)
   M5 = (A11 + A12) * B22
   M6 = (A21 - A11) * (B11 + B12)
   M7 = (A12 - A22) * (B21 + B22)
   ```

3. **Combine** these 7 products with matrix additions/subtractions to
   form the four quadrants of the result matrix `C`.
4. Recurse until the sub-matrices are small enough (base case, e.g.
   `1 × 1`) to multiply directly.
5. Matrices are padded to the next power of 2 if `n` is not already a
   power of 2, so the recursive halving always divides evenly.

## Complexity

- **Recurrence:** T(n) = 7T(n/2) + O(n²)
- **Time Complexity:** O(n^log₂7) ≈ O(n^2.81), an improvement over the
  standard O(n³) matrix multiplication algorithm.

## File Structure

```
Q4/
├── strassen_matrix.c   # Source code
├── strassen_matrix.exe # Compiled executable (Windows)
└── README.md
```

## How to Build

```bash
gcc -o strassen_matrix strassen_matrix.c
```

On Windows:

```bash
gcc -o strassen_matrix.exe strassen_matrix.c
```

## How to Run

```bash
./strassen_matrix
```

The program prompts for:
1. The matrix size `n`.
2. The elements of matrix `A` and matrix `B`.

It then prints the product matrix `C = A × B`, computed using Strassen's
divide-and-conquer method.

## Sample Output

```
Enter matrix size n: 2
Enter matrix A: 1 2 3 4
Enter matrix B: 5 6 7 8

Result C = A x B:
19 22
43 50
```
