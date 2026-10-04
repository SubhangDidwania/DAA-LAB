# DAA Lab 8 - Problem 4
## Longest Increasing Subsequence

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E2)-green)

---

## Problem Statement

Given an integer array `A = [a0, a1, ..., an-1]`, find the length of the longest subsequence such that all elements of the subsequence are strictly increasing.

## Objective

The objective is to find the longest increasing sequence while preserving the relative order of the original array.

## Concept Used - Dynamic Programming

Let `dp[i]` be the length of the LIS that ends at index `i`.

```text
dp[i] = 1
for j = 0 to i-1:
    if arr[j] < arr[i]:
        dp[i] = max(dp[i], dp[j] + 1)
```

## Algorithm

```text
1. Read the number of elements n.
2. Initialize dp[i] = 1 for all i.
3. For each index i:
4.     For each previous index j:
5.         If arr[j] < arr[i], update dp[i].
6. Print the maximum value in dp.
```

## Implementation

File:

```text
04_longest_increasing_subsequence.c
```

## Input

```text
8
10 22 9 33 21 50 41 60
```

## Output

```text
Length of LIS: 5
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| LIS DP | `O(n^2)` | `O(n)` |
| Total | `O(n^2)` | `O(n)` |

## Important Test Cases

| Array | Expected output |
|---|---:|
| `10, 22, 9, 33, 21, 50, 41, 60` | `5` |
| `3, 1, 2` | `2` |
| `7, 7, 7` | `1` |
| `1, 2, 3, 4` | `4` |

## Compilation and Execution

```bash
gcc 04_longest_increasing_subsequence.c -o lis
./lis
```

Windows:

```powershell
gcc 04_longest_increasing_subsequence.c -o lis.exe
.\lis.exe
```
