# Multiplying Special-Pattern Square Matrices using Divide and Conquer

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CSE-B), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

Two `n × n` matrices are given, where `n = 2^k` for some natural number
`k`. Each matrix has a special recursive block structure: when split into
four equal-sized blocks, the two diagonal blocks are identical and the two
off-diagonal blocks are identical, i.e.

```
M = | M1  M2 |
    | M2  M1 |
```

This pattern holds recursively down to single-element blocks. The task is
to design a divide-and-conquer algorithm that exploits this structure to
multiply two such matrices in **O(n²)** time — much faster than general
`O(n³)` (or even Strassen's `O(n^2.81)`) matrix multiplication — and to
validate the achieved complexity.

## Approach (Divide and Conquer)

Let `A` and `B` both have the special form:

```
A = | A1  A2 |        B = | B1  B2 |
    | A2  A1 |             | B2  B1 |
```

Multiplying them out:

```
A*B = | A1*B1 + A2*B2   A1*B2 + A2*B1 |
      | A2*B1 + A1*B2   A2*B2 + A1*B1 |
```

The result **also has the same special form** — the top-left block equals
the bottom-right block (`A1*B1 + A2*B2`), and the top-right block equals
the bottom-left block (`A1*B2 + A2*B1`). This means:

1. Only **two** distinct sub-blocks of the result need to be computed
   instead of four.
2. Each of those two sub-blocks needs only **two** recursive
   multiplications of `n/2 × n/2` special-pattern matrices (`A1*B1`,
   `A2*B2`, `A1*B2`, `A2*B1` — but `A1`, `A2`, `B1`, `B2` are themselves
   special-pattern matrices, so the recursion continues).
3. The recursion bottoms out at `1 × 1` matrices (plain integers).

Because the sub-problems and result share the same recursive structure,
the recurrence for the number of scalar multiplications is:

```
T(n) = 4T(n/2) + O(n²/4)   [combining/adding blocks]
```

which resolves to **O(n²)**, since the special structure avoids the
extra recursive multiplications that a generic divide-and-conquer
matrix multiplication would require.

## Complexity

- **Recurrence:** T(n) = 4T(n/2) + O(n²)
- **Time Complexity:** O(n²) — validated empirically by timing runs at
  increasing sizes `n = 2^k` and confirming the growth rate matches `n²`.

## File Structure

```
Q5/
├── special_matrix.c   # Source code
├── special_matrix.exe # Compiled executable (Windows)
└── README.md
```

## How to Build

```bash
gcc -o special_matrix special_matrix.c
```

On Windows:

```bash
gcc -o special_matrix.exe special_matrix.c
```

## How to Run

```bash
./special_matrix
```

The program prompts for:
1. `k`, where the matrix size is `n = 2^k`.
2. The unique elements needed to construct each special-pattern matrix
   (`A1`, `A2` and `B1`, `B2` recursively).

It prints the resulting product matrix and the measured running time
across increasing `n`, to validate the `O(n²)` bound.

## Sample Output

```
Enter k (matrix size n = 2^k): 2   (n = 4)
Matrix A and B generated with special block pattern.

Result matrix C:
...

n = 4    time = 0.00001s
n = 8    time = 0.00004s
n = 16   time = 0.00016s   (≈ 4x growth, consistent with O(n^2))
```
