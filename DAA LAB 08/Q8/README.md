# DAA Lab 8 - Problem 8
## Optimal Binary Search Tree (OBST)

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E3)-green)

---

## Problem Statement

Given a set of `n` distinct sorted keys `K = <k1, k2, ..., kn>` with their search probabilities `p1, p2, ..., pn`, and dummy keys `d0, d1, ..., dn` with probabilities `q0, q1, ..., qn`, find the minimum expected search cost of a binary search tree.

## Objective

The objective is to construct an optimal binary search tree that minimizes total search cost under the given probabilities.

## Concept Used - Dynamic Programming

Let `dp[i][j]` be the minimum search cost for the subproblem containing keys `ki...kj`.

```text
dp[i][j] = min over root r in [i, j] of
    dp[i][r-1] + dp[r+1][j] + weight(i, j)
```

Where `weight(i, j)` is the total probability of keys and dummy keys in that interval.

## Algorithm

```text
1. Input the keys, search probabilities p, and dummy probabilities q.
2. Compute the total weight for each interval.
3. For each interval length from 1 to n:
4.     Try each possible root position.
5.     Select the root that minimizes the expected cost.
6. Print the minimum expected cost.
```

## Implementation

File:

```text
08_optimal_binary_search_tree.c
```

## Input

```text
4
10 20 30 40
1 2 3 4
0 1 2 3 4
```

## Output

```text
Minimum expected cost: <computed value>
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP over intervals | `O(n^3)` | `O(n^2)` |
| Total | `O(n^3)` | `O(n^2)` |

## Important Test Cases

| Keys | Probabilities | Expected result |
|---|---|---|
| `10, 20, 30` | `1, 2, 3` | minimal cost tree |
| `1, 2, 3, 4` | `0.1, 0.2, 0.3, 0.4` | minimal cost tree |
| `5, 10` | `0.5, 0.5` | minimal cost tree |

## Compilation and Execution

```bash
gcc 08_optimal_binary_search_tree.c -o obst
./obst
```

Windows:

```powershell
gcc 08_optimal_binary_search_tree.c -o obst.exe
.\obst.exe
```
