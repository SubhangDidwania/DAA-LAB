# DAA Lab 9 - Problem 9
## Hu-Tucker Greedy Simulation

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Hu-Tucker%20Greedy-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E3)-green)

---

## Problem Statement

You are given an ordered sequence of weights `w1, w2, ..., wn`. Construct an optimal alphabetic binary merge pattern that preserves the in-order sequence of indices while minimising

`sum (w_i * depth(i))`.

## Objective

The goal is to maintain the strict order of leaves while minimising the weighted external path length.

## Concept Used - Hu-Tucker Inspired Order-Preserving Merge

The merge process keeps the sequence ordered while selecting the best pair of adjacent blocks, which is the core idea behind Hu-Tucker style greedy optimisation.

## Algorithm

```text
1. Read the ordered weights.
2. Use a dynamic-programming formulation over intervals.
3. Let dp[i][j] represent the minimum cost for the subarray i..j.
4. For each split k, compute the combined cost plus the total weight of the interval.
5. Reconstruct the optimal split and print the minimum weighted depth.
```

## Implementation

File:

```text
09_hu_tucker.c
```

## Sample Input

```text
4
1 2 3 4
```

## Sample Output

```text
Minimum weighted depth: 19
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Interval DP | `O(n^3)` | `O(n^2)` |
| Total | `O(n^3)` | `O(n^2)` |

## Important Test Cases

| Weights | Output |
|---|---|
| `1 2 3 4` | `19` |
| `1 1 1 1` | `8` |
| `5 2 7` | `31` |

## Compilation and Execution

```bash
gcc 09_hu_tucker.c -o hutucker
./hutucker
```

Windows:

```powershell
gcc 09_hu_tucker.c -o hutucker.exe
.\hutucker.exe
```
