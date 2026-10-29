# DAA Lab 8 - Problem 7
## Rod Cutting with Reconstruction

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E2)-green)

---

## Problem Statement

Given a rod of length `n` inches and an array of prices `P = [p1, p2, ..., pn]`, where `pi` is the market price of a rod piece of length `i`, determine:

1. The maximum revenue obtainable by cutting the rod and selling the pieces.
2. The exact lengths of the pieces that form the optimal decomposition.

Cuts are integral and can be made in any combination, including leaving the rod uncut.

## Objective

The objective is to maximize revenue while ensuring the sum of the piece lengths equals the original rod length.

## Concept Used - Dynamic Programming

Let `dp[len]` be the maximum revenue obtainable from a rod of length `len`.

```text
dp[0] = 0
for length = 1 to n:
    dp[length] = max over cut sizes k:
        price[k] + dp[length - k]
```

A separate `choice` array stores the best cut size for each length so the optimal decomposition can be reconstructed.

## Algorithm

```text
1. Read the rod length n and the price array.
2. Initialize dp[0] = 0.
3. For each length from 1 to n:
4.     Try every possible first cut.
5.     Store the best revenue and associated cut size.
6. Reconstruct the piece lengths from the final value.
7. Print the maximum revenue and the decomposition.
```

## Implementation

File:

```text
07_rod_cutting_with_reconstruction.c
```

## Input

```text
8
1 5 8 9 10 17 17 20 24 30
```

## Output

```text
Maximum revenue: 22
Optimal pieces: 2 6
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP states | `O(n^2)` | `O(n)` |
| Reconstruction | `O(n)` | `O(1)` extra |
| Total | `O(n^2)` | `O(n)` |

## Important Test Cases

| Rod length | Prices | Expected output |
|---|---|---|
| `8` | `1,5,8,9,10,17,17,20,24,30` | `22` |
| `1` | `1` | `1` |
| `4` | `2, 5, 7, 8` | `10` |
| `5` | `2, 5, 7, 8, 10` | `12` |

## Compilation and Execution

```bash
gcc 07_rod_cutting_with_reconstruction.c -o rod_cut
./rod_cut
```

Windows:

```powershell
gcc 07_rod_cutting_with_reconstruction.c -o rod_cut.exe
.\rod_cut.exe
```
