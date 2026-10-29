# DAA Lab 8 - Problem 6
## Edit Distance with Traceback Information

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(mn)-green)

---

## Problem Statement

Given two strings `A` and `B`, compute the minimum number of operations required to convert `A` into `B`. The allowed operations are insertion, deletion, and substitution.

The program should also print the traceback information showing the operations performed.

## Objective

The objective is to find the minimum transformation cost and recover a trace of the edit operations used.

## Concept Used - Dynamic Programming

Let `dp[i][j]` be the minimum number of operations required to transform the first `i` characters of `A` into the first `j` characters of `B`.

```text
if A[i-1] == B[j-1]:
    dp[i][j] = dp[i-1][j-1]
else:
    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
```

Backtracking through the DP table prints the sequence of edit operations.

## Algorithm

```text
1. Read strings A and B.
2. Build the edit-distance DP table.
3. Fill values based on insertion, deletion, and substitution.
4. Reconstruct the operation sequence by walking backward through the matrix.
5. Print the minimum distance and traceback path.
```

## Implementation

File:

```text
06_edit_distance_with_traceback.c
```

## Input

```text
kitten
sitting
```

## Output

```text
Minimum edit distance: 3
Traceback path:
...
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP computation | `O(m * n)` | `O(m * n)` |
| Traceback | `O(m + n)` | `O(1)` extra |
| Total | `O(m * n)` | `O(m * n)` |

## Important Test Cases

| String A | String B | Expected output |
|---|---|---|
| `kitten` | `sitting` | `3` |
| `abc` | `abc` | `0` |
| `abc` | `def` | `3` |
| `sunday` | `saturday` | `3` |

## Compilation and Execution

```bash
gcc 06_edit_distance_with_traceback.c -o edit_dist
./edit_dist
```

Windows:

```powershell
gcc 06_edit_distance_with_traceback.c -o edit_dist.exe
.\edit_dist.exe
```
