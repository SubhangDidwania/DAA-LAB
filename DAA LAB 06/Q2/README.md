# DAA Lab-06 — Question 2

## 2D Square Matrix Operations and Complexity Analysis

### Problem Statement

Given square matrices of size `n × n`, determine the worst-case computational complexity of:

1. Matrix addition
2. Matrix multiplication
3. Checking whether a matrix is a zero matrix
4. Checking whether a matrix is symmetric
5. Computing the determinant
6. In-place matrix transpose
7. Finding eigenvalues and eigenvectors

A C program is used to validate the basic matrix operations.

---

## Concepts Used

* Two-dimensional arrays
* Matrix addition
* Matrix multiplication
* Matrix traversal
* Symmetric matrices
* Transpose
* Determinant
* Eigenvalues and eigenvectors
* Time complexity analysis

---

## Algorithms

### 1. Matrix Addition

Each corresponding pair of elements is added:

$$
C[i][j] = A[i][j] + B[i][j]
$$

There are `n²` elements.

**Complexity:** `O(n²)`

### 2. Matrix Multiplication

Each element of the result requires `n` multiplications/additions.

$$
C[i][j] = \sum_{k=0}^{n-1} A[i][k]B[k][j]
$$

There are `n²` result elements.

**Complexity:** `O(n³)`

### 3. Zero Matrix

Traverse the matrix and check whether every element is zero.

**Complexity:** `O(n²)`

### 4. Symmetric Matrix

A matrix is symmetric if:

$$
A[i][j] = A[j][i]
$$

Only one triangular half needs to be checked.

**Complexity:** `O(n²)`

### 5. Determinant

Using recursive cofactor expansion, the determinant is calculated by recursively computing determinants of smaller matrices.

**Complexity:** `O(n!)`

> The complexity depends on the determinant algorithm. The above complexity refers to the recursive cofactor-expansion approach.

### 6. In-Place Transpose

Swap:

$$
A[i][j] \leftrightarrow A[j][i]
$$

for elements above the main diagonal.

**Time Complexity:** `O(n²)`

**Extra Space:** `O(1)`

### 7. Eigenvalues and Eigenvectors

Standard numerical methods such as QR-based methods typically require approximately cubic time.

**Complexity:** `O(n³)`

---

## Complexity Summary

| Operation                  | Worst-Case Complexity |
| -------------------------- | --------------------: |
| Matrix Addition            |               `O(n²)` |
| Matrix Multiplication      |               `O(n³)` |
| Zero Matrix                |               `O(n²)` |
| Symmetric Matrix           |               `O(n²)` |
| Determinant (Cofactor)     |               `O(n!)` |
| In-Place Transpose         |               `O(n²)` |
| Eigenvalues & Eigenvectors |               `O(n³)` |

---

## Input

The program takes:

* Matrix size `n`
* Elements of matrix `A`
* Elements of matrix `B`

---

## Output

The program displays:

* Matrix addition
* Matrix multiplication
* Whether the matrix is zero
* Whether the matrix is symmetric
* Transpose of the matrix

---

## Compilation

```bash
gcc Matrix2D.c -o Matrix2D
```

## Execution

```bash
./Matrix2D
```

---

## Key Takeaway

Matrix operations generally require at least `O(n²)` time because an `n × n` matrix contains `n²` elements. Matrix multiplication requires `O(n³)` time using the standard algorithm because every result element requires a traversal of a complete row/column pair.
