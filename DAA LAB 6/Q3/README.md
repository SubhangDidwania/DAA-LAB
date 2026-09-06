# DAA Lab-06 — Question 3

## Convolution of Two Vectors Using Divide and Conquer

### Problem Statement

Given two vectors `A` and `B` of lengths `m` and `n`, respectively, where:

$$
n \geq m
$$

compute their convolution:

$$
C[k] = \sum_{j=0}^{m-1} A[j]B[k-j]
$$

The objective is to design an `O(n log n)` divide-and-conquer algorithm.

---

## Concepts Used

* Vector convolution
* Polynomial multiplication
* Divide and conquer
* Fast Fourier Transform (FFT)
* Recursive algorithms
* Complex numbers
* Time complexity analysis

---

## Convolution

The convolution of two vectors produces a new vector whose elements are obtained by multiplying overlapping elements and summing the results.

For example:

```text
A = [1, 2]
B = [3, 4, 5]
```

The convolution is:

```text
[3, 10, 13, 10]
```

because:

```text
C[0] = 1×3
C[1] = 1×4 + 2×3
C[2] = 1×5 + 2×4
C[3] = 2×5
```

---

## Naive Approach

The direct implementation uses nested loops.

For every pair of elements:

```text
A[i] × B[j]
```

is calculated.

Therefore:

**Time Complexity:** `O(n²)`

This does not satisfy the required `O(n log n)` complexity.

---

## Divide-and-Conquer Approach

Convolution can be viewed as **polynomial multiplication**.

If:

$$
A(x)=\sum A[i]x^i
$$

and:

$$
B(x)=\sum B[i]x^i
$$

then their product contains the convolution coefficients.

Fast Fourier Transform (FFT) allows polynomial evaluation and multiplication efficiently.

### Steps

1. Pad both vectors to a suitable power-of-two size.
2. Apply FFT to vector `A`.
3. Apply FFT to vector `B`.
4. Multiply corresponding frequency-domain values.
5. Apply inverse FFT.
6. The resulting coefficients form the convolution.

---

## Complexity

FFT satisfies the recurrence:

$$
T(n)=2T(n/2)+O(n)
$$

Using the Master Theorem:

$$
T(n)=O(n\log n)
$$

Only a constant number of FFT operations are required.

Therefore:

$$
\boxed{O(n\log n)}
$$

---

## Input

The program takes:

* Length `m` of vector `A`
* Length `n` of vector `B`
* Elements of `A`
* Elements of `B`

with:

$$
n \geq m
$$

---

## Output

The convolution vector is printed after performing FFT-based multiplication.

---

## Compilation

```bash
gcc convolution.c -o convolution -lm
```

## Execution

```bash
./convolution
```

---

## Key Takeaway

The important observation is:

> **Convolution of two vectors is equivalent to multiplication of their corresponding polynomials.**

FFT reduces polynomial multiplication from the naive `O(n²)` approach to:

$$
\boxed{O(n\log n)}
$$

which satisfies the requirement of the problem.
