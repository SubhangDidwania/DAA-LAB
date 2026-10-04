# DAA Lab 8 - Problem 3
## Longest Common Subsequence (LCS)

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(mn)-green)

---

## Problem Statement

Given two sequences `X = <x1, x2, ..., xm>` and `Y = <y1, y2, ..., yn>`, compute the length of their longest common subsequence and reconstruct the actual subsequence string.

## Objective

The objective is to identify the longest sequence of elements that appears in both strings in order, but not necessarily consecutively.

## Concept Used - Dynamic Programming

Let `dp[i][j]` be the LCS length of prefixes `X[0..i-1]` and `Y[0..j-1]`.

```text
if X[i-1] == Y[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

Backtracking from `dp[m][n]` reconstructs the subsequence.

## Algorithm

```text
1. Read the two strings X and Y.
2. Compute the LCS DP table.
3. If characters match, move diagonally and add the character.
4. Otherwise, move to the larger neighboring value.
5. Reverse the reconstructed result and print it.
```

## Implementation

File:

```text
03_longest_common_subsequence.c
```

## Input

```text
ABCBDAB
BDCAB
```

## Output

```text
Length of LCS: 4
LCS: BCBA
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP table construction | `O(m * n)` | `O(m * n)` |
| Reconstruction | `O(m + n)` | `O(1)` extra |
| Total | `O(m * n)` | `O(m * n)` |

## Important Test Cases

| Sequence X | Sequence Y | Expected result |
|---|---|---|
| `ABC` | `AC` | `2` |
| `ABCBDAB` | `BDCAB` | `4` |
| `A` | `B` | `0` |
| `HELLO` | `ELLO` | `4` |

## Compilation and Execution

```bash
gcc 03_longest_common_subsequence.c -o lcs
./lcs
```

Windows:

```powershell
gcc 03_longest_common_subsequence.c -o lcs.exe
.\lcs.exe
```
