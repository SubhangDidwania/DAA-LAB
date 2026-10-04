# DAA Lab 8 - Problem 5
## Maximum Sum Increasing Subsequence

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E2)-green)

---

## Problem Statement

Given an array of `n` positive integers `A = [a0, a1, ..., an-1]`, find the maximum possible sum of a strictly increasing subsequence.

## Objective

The objective is to maximize the total sum of a subsequence where each chosen value is greater than the previous chosen value.

## Concept Used - Dynamic Programming

Let `dp[i]` represent the maximum sum of an increasing subsequence that ends at index `i`.

```text
dp[i] = arr[i]
for j = 0 to i-1:
    if arr[j] < arr[i]:
        dp[i] = max(dp[i], dp[j] + arr[i])
```

## Algorithm

```text
1. Read the array of n positive integers.
2. Initialize dp[i] = arr[i].
3. For each index i, check all previous indices j.
4. If arr[j] < arr[i], update dp[i].
5. Return the maximum value in dp.
```

## Implementation

File:

```text
05_maximum_sum_increasing_subsequence.c
```

## Input

```text
7
1 5 2 4 3 6 8
```

## Output

```text
Maximum sum of an increasing subsequence: 22
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP calculation | `O(n^2)` | `O(n)` |
| Total | `O(n^2)` | `O(n)` |

## Important Test Cases

| Array | Expected output |
|---|---:|
| `1, 5, 2, 4, 3, 6, 8` | `22` |
| `3, 4, 5, 1` | `12` |
| `2, 1, 5` | `7` |
| `10, 5, 20, 30` | `60` |

## Compilation and Execution

```bash
gcc 05_maximum_sum_increasing_subsequence.c -o msis
./msis
```

Windows:

```powershell
gcc 05_maximum_sum_increasing_subsequence.c -o msis.exe
.\msis.exe
```
