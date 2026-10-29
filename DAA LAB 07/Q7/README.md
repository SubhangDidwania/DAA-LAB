# DAA Lab 7 - Problem 7
## Matrix Chain Multiplication

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(N%5E3)-green)

---

## Problem Statement

Given a chain of matrices, find the parenthesization that minimizes the number of scalar multiplications required to compute the final product.

The order of the matrices cannot change, but the order of multiplication can change.

## Objective

The objective is to calculate both:

1. The minimum number of scalar multiplications.
2. The corresponding optimal parenthesization.

## Concept Used - Dynamic Programming

If matrix `Ai` has dimensions `p[i-1] x p[i]`, then splitting the chain `Ai...Aj` at `Ak` costs:

```text
cost[i][k] + cost[k+1][j]
	+ p[i-1] * p[k] * p[j]
```

The program stores the best split in `split[i][j]` and uses it to reconstruct the order.

## Algorithm

```text
1. Read n matrices and n + 1 dimensions.
2. Set the cost of a single matrix to zero.
3. Consider chain lengths from 2 to n.
4. Try every possible split k for each chain.
5. Store the minimum cost and its split position.
6. Recursively print the optimal parenthesization.
```

## Implementation

File:

```text
matrix_chain.c
```

## Input

For matrices with dimensions `40x20`, `20x30`, `30x10`, and `10x30`:

```text
Enter the number of matrices: 4
Enter 5 matrix dimensions: 40 20 30 10 30
```

## Output

```text
Minimum scalar multiplications: 26000
Order: ((A1(A2A3))A4)
```

## Complexity Analysis

| Operation | Complexity |
|---|---:|
| Number of DP states | `O(n^2)` |
| Splits tested per state | `O(n)` |
| Total time | `O(n^3)` |
| DP table space | `O(n^2)` |

## Important Test Cases

- One matrix: zero multiplications
- Two matrices: one multiplication
- Different parenthesizations with different costs
- Equal dimensions
- Large chain length within the program limit

## Compilation and Execution

```bash
gcc matrix_chain.c -o matrix_chain
./matrix_chain
```

Windows:

```powershell
gcc matrix_chain.c -o matrix_chain.exe
.\matrix_chain.exe
```